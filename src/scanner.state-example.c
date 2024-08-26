/*
Limitations:
  - We can't lookahead more than one character
  - We can't go back once we've advanced or skipped
*/

// TESTS: [x] 1 closing sign containing a 2 and a 0 before end
// TESTS: [x] 2 closing sign containing a 1, a 0, and a 3 before end

// Strings
// [x] Can we serialize state with nothing operating on it?
// [x] String opening block and closing block
// [x] Make string_block read string_block_content and string_escape as optional repeats in the middle of start and end
// [] Read docs on Nelua Preprocessor, then add handles for that (remember that injections will happen through a queries file, so worth reading docs on that, and on testing that)
// [nope] Add escape string scanning to grammar (make sure to support hex, decimal, etc. Check the PEG)
// [ ] actually escape strings don't count inside a block string, so we should instead remove state and do all string parsing in a single go
// [ ] 

#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <wctype.h>
enum TokenType {
  SHORT_COMMENT,
  LONG_COMMENT,
  STRING_BLOCK_START,
  STRING_CONTENT,
  STRING_BLOCK_END,
  // LONG_COMMENT_END,
  // should never be used in grammar.js.
  // this allows us to determine if we're in error recovery
  ERROR_SENTINEL,
};

typedef struct {
  uint8_t level;
} Scanner;

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

static inline void reset(Scanner *scanner) {
  scanner->level = 0;
}

static inline void skip_whitespace(TSLexer *lexer) {
  while (iswspace(lexer->lookahead)) {
    skip(lexer);
  }
}

#define ADVANCE_OR_FALSE(lexer, given_char) \
  if ((lexer)->lookahead == (given_char)) { \
    advance(lexer); \
  } else { \
    return false; \
  }

void *tree_sitter_neluablk_external_scanner_create() { 
  printf("create>top\n");
  Scanner *scanner = (Scanner *)ts_calloc(1, sizeof(Scanner));
  memset(scanner, 0, sizeof(Scanner));
  return scanner;
  // return NULL;
}

void tree_sitter_neluablk_external_scanner_destroy(void *payload) {
  printf("destroy>top\n");
  Scanner *scanner = (Scanner *)payload;
  ts_free(scanner);
}  

unsigned tree_sitter_neluablk_external_scanner_serialize(void *payload, char *buffer) { 
  printf("serialize>top\n");
  Scanner *scanner = (Scanner *)payload;
  *buffer = scanner->level; 
  printf("serialize> serialized buffer to level %d\n", *buffer);
  return 1; 
}

void tree_sitter_neluablk_external_scanner_deserialize
(void *payload, char *buffer, unsigned length) {
  printf("deserialize>top with length %d\n", length);
  assert(length < 2 && "Invalid scanner length received by deserialize, expected 1");
  Scanner *scanner = (Scanner *)payload;
  if (length == 0) {
    printf("deserialize> empty length, setting level to 0\n");
    scanner->level = 0;
  } else {
    printf("deserialize> setting level to %d\n", scanner->level);
    scanner->level = *buffer;
  }
}
  // assert(length >= 0 && length < 2 && "Invalid scanner length received by deserialize, expected 1");
  // Scanner *scanner = (Scanner *)payload;
  // scanner->level = neluablk

const uint8_t SHORT_COMMENT_RET_FALSE = 0;
const uint8_t SHORT_COMMENT_RET_TRUE = 1;
// We've been advancing the lexer, so we need to take over with long comment logic if able.
const uint8_t SHORT_COMMENT_RET_ISLONG = 2;

static bool scan_short_comment(TSLexer *lexer) {
  printf("Top of scan short comment!\n");
  ADVANCE_OR_FALSE(lexer, '-')
  ADVANCE_OR_FALSE(lexer, '-')
  printf("SSC>Checkpoint 1\n");

  bool is_long_comment = false;
  // how many "=" do we expect to close?
  uint8_t closing_signs = 0;
  if (lexer->lookahead == '[') {
    printf("SSC>Found [\n");
      // Advance past all equal signs
    for (;;) {
      advance(lexer);
      if (lexer->eof(lexer)) {
        printf("SSC>Found EOF in [ check\n");
        return false;
      }
      if (lexer->lookahead != '=') {
        printf("SSC>Out of equal signs\n");
        break;
      }
      closing_signs++;
    }

    if (lexer->lookahead == '[') {
      printf("SSC>Decided this is a long comment!\n");
      // We are a long comment, abort
      lexer->result_symbol = LONG_COMMENT;
      is_long_comment = true;
      // return true;
    } else {
      // this isn't a closing comment, reset closing signs just in case
      closing_signs = 0;
    }
  }

  if (is_long_comment) {
    for (;;) { 
      // stop at eof
      if (lexer->eof(lexer)) {
        printf("long_comment>EOF\n");
        return true;
      }
      // When we find ] we start to check
      if (lexer->lookahead == ']') {
        printf("long_comment>found first ]\n");
        // TODO: Consume correct amount of equal signs
        advance(lexer);

         if (lexer->eof(lexer)) {
           printf("long_comment>EOF\n");
           return true;
        }
        // If we don't match a certain amount of equal signs, we aren't eligible to close.  That amount can be 0.
        bool should_look_for_end = true;
        printf("closing signs: %d\n", closing_signs);
        for (uint8_t i = 0; i < closing_signs; i++) {
          if (lexer->lookahead != '=') {
            should_look_for_end = false;
            // we don't want to advance here, as we'll advance at the end of the outer loop
            break;
          }
          advance(lexer);
           if (lexer->eof(lexer)) {
             printf("long_comment>EOF\n");
             return true;
          }
        }

        if (should_look_for_end && lexer->lookahead == ']') {
          printf("Found end of long comment!\n");
          advance(lexer);
          return true;
        }
      }
      // At this point we accept anything
      advance(lexer);
    }
  }

  // Short comments go until 
  for (;;) {
    if (lexer->eof(lexer)) {
      printf("SSC>EOF\n");
      return true;
    }
    if (lexer->lookahead == '\r') {
      printf("SSC>Found slash r\n");
      advance(lexer);
      continue;
    }

    if (lexer->lookahead == '\n') {
      printf("SSC>Found slash n, returning true!\n");
      skip(lexer);
      return true;
    }

    advance(lexer);
    printf("SSC>Advanced!\n");
  }
  printf("SSC>Returning true after loop\n");
  return true;
}

static bool scan_string_block_start(Scanner *scanner, TSLexer *lexer) {
  printf("scan_string_block_start>\n");
  ADVANCE_OR_FALSE(lexer, '[')
  uint8_t closing_signs = 0;
  if (lexer->lookahead == '=') {
    for (;;) {
      advance(lexer);
      closing_signs++;
      if (lexer->eof(lexer)) {
        printf("scan_string_block_start>Found EOF in = check\n");
        return false;
      }
      if (lexer->lookahead != '=') {
        printf("scan_string_block_start>Out of equal signs\n");
        break;
      }
    }
  }
  ADVANCE_OR_FALSE(lexer, '[')
  scanner->level = closing_signs;
  return true;
}

static bool scan_string_block_end(Scanner *scanner, TSLexer *lexer) {
  ADVANCE_OR_FALSE(lexer, ']')
  for (uint8_t i = 0; i < scanner->level; i++) {
    ADVANCE_OR_FALSE(lexer, '=')
  }
  ADVANCE_OR_FALSE(lexer, ']')
  reset(scanner);
  return true;
}

static bool scan_string_content(TSLexer *lexer) {
  // If we are handed a ] immediately, its already been confirmed to not be a valid ender, so we can just keep scanning.
  // if (lexer->lookahead == ']') {
  //   advance(lexer);
  // }

  for (;;) {
    if (lexer->eof(lexer)) {
      // I think we return false here, unless it feels nicer to highlight as a string.
      return false;
    }
    if (lexer->lookahead == ']') {
      // return without consuming, because we want to trigger a check for end content
      return true;
    }
    // otherwise we just keep consuming everything
    advance(lexer);
  }
}

bool tree_sitter_neluablk_external_scanner_scan 
(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  Scanner *scanner = (Scanner *)payload;
  printf("Scanner level %d\n", scanner->level);
  // if (valid_symbols[LONG_COMMENT_START] && valid_symbols[LONG_COMMENT_END]) {
  //   // We're in error recovery
  //   return false;
  // }
  if (valid_symbols[ERROR_SENTINEL]) {
    printf("ERROR_SENTINEL\n");
    return false;
  }
  if (valid_symbols[SHORT_COMMENT]) {
    printf("Valid: Short Comment\n");
  }
  if (valid_symbols[LONG_COMMENT]) {
    printf("Valid: Long Comment\n");
  }

  skip_whitespace(lexer);

  if (lexer->lookahead == '-' && valid_symbols[SHORT_COMMENT] && valid_symbols[LONG_COMMENT]) {
    printf("In SHORT_COMMENT/LONG_COMMENT main branch\n");
    lexer->result_symbol = SHORT_COMMENT;
    if (scan_short_comment(lexer)) {
      return true;
    }
  }

  if (lexer->lookahead == '[' && valid_symbols[STRING_BLOCK_START]) {
    printf("In STRING_BLOCK_START, scanner->level %d\n", scanner->level);
    lexer->result_symbol = STRING_BLOCK_START;
    reset(scanner);
    return scan_string_block_start(scanner, lexer);
  }

  if (lexer->lookahead == ']' && valid_symbols[STRING_BLOCK_END] && valid_symbols[STRING_CONTENT]) {
    printf("In STRING_BLOCK_END\n");
    lexer->result_symbol = STRING_BLOCK_END;
    bool scan_block_res = scan_string_block_end(scanner, lexer);
    if (scan_block_res) {
      return true;
    }

    printf("NOT the end, checking string content\n");
    // This wasn't a valid ending, so we'll take what we've consumed so far and return it as string_content
    lexer->result_symbol = STRING_CONTENT;
    return scan_string_content(lexer);
  }

  if (lexer->lookahead == '\\' && valid_symbols[ESCAPE_CHARACTER]) {
  }

  if (valid_symbols[STRING_CONTENT]) {
    printf("In STRING_CONTENT\n");
    lexer->result_symbol = STRING_CONTENT;
    return scan_string_content(lexer);
  }

  printf("external scanner> Falling through to return false\n");
  return false;
}
 
