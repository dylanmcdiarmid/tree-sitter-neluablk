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
// [nope] Add escape string scanning to grammar (make sure to support hex, decimal, etc. Check the PEG)
// [x] actually escape strings don't count inside a block string, so we should instead remove state and do all string parsing in a single go
// [x] Read docs on Nelua Preprocessor, then add handles for that (remember that injections will happen through a queries file, so worth reading docs on that, and on testing that)
// [ ] Bring start, middle, end for comment parsing
// [ ] DRY some repetitive logic

#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <wctype.h>
enum TokenType {
  SHORT_COMMENT_START,
  LONG_COMMENT_START,
  LONG_COMMENT_BODY,
  LONG_COMMENT_END,
  STRING_BLOCK,
  SHORT_PP_START,
  LONG_PP_START,
  LONG_PP_BODY,
  LONG_PP_END,
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

static inline void skip_whitespace(TSLexer *lexer) {
  while (iswspace(lexer->lookahead)) {
    skip(lexer);
  }
}

static inline void reset(Scanner *scanner) {
  scanner->level = 0;
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

void tree_sitter_neluablk_external_scanner_deserialize(void *payload, char *buffer, unsigned length) { 
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

// const uint8_t SHORT_COMMENT_RET_FALSE = 0;
// const uint8_t SHORT_COMMENT_RET_TRUE = 1;
// We've been advancing the lexer, so we need to take over with long comment logic if able.
// const uint8_t SHORT_COMMENT_RET_ISLONG = 2;
static bool scan_comment_start(Scanner *scanner, TSLexer *lexer) {
  printf("Top of scan short comment!\n");
  ADVANCE_OR_FALSE(lexer, '-')
  ADVANCE_OR_FALSE(lexer, '-')
  printf("SSC>Checkpoint 1\n");
  // If we detect we're in a long comment start, we'll mark the end somewhere else
  lexer->mark_end(lexer);

  // how many "=" do we expect to close?
  uint32_t closing_signs = 0;
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
      advance(lexer);
      scanner->level = closing_signs;
      // move mark end
      lexer->mark_end(lexer);
      // We are a long comment, abort
      lexer->result_symbol = LONG_COMMENT_START;
      // return true;
    } else {
      // this isn't a closing comment, reset closing signs just in case
      closing_signs = 0;
      reset(scanner);
    }
  }
  return true;
}

static bool scan_pp_start(Scanner *scanner, TSLexer *lexer) {
  printf("Top of scan pp start!\n");
  ADVANCE_OR_FALSE(lexer, '#')
  ADVANCE_OR_FALSE(lexer, '#')
  // If we detect we're in a long comment start, we'll mark the end somewhere else
  lexer->mark_end(lexer);

  // how many "=" do we expect to close?
  uint32_t closing_signs = 0;
  if (lexer->lookahead == '[') {
    printf("PPS>Found [\n");
      // Advance past all equal signs
    for (;;) {
      advance(lexer);
      if (lexer->eof(lexer)) {
        printf("PPS>Found EOF in [ check\n");
        return false;
      }
      if (lexer->lookahead != '=') {
        printf("PPS>Out of equal signs\n");
        break;
      }
      closing_signs++;
    }

    if (lexer->lookahead == '[') {
      printf("PPS>Decided this is a long pp\n");
      advance(lexer);
      scanner->level = closing_signs;
      // move mark end
      lexer->mark_end(lexer);
      // We are a long comment, abort
      lexer->result_symbol = LONG_PP_START;
      // return true;
    } else {
      // this isn't a closing comment, reset closing signs just in case
      closing_signs = 0;
      reset(scanner);
    }
  }
  return true;
}

static bool scan_body(Scanner *scanner, TSLexer *lexer) {
  for (;;) { 
    // if we are potentially at the end
    // stop at eof
    if (lexer->eof(lexer)) {
      printf("long_comment>EOF\n");
      return true;
    }
    // When we find ] we are potentially at the end
    if (lexer->lookahead == ']') {
      lexer->mark_end(lexer);
      printf("long_comment>found first ]\n");
      // TODO: Consume correct amount of equal signs
      advance(lexer);

       if (lexer->eof(lexer)) {
         printf("long_comment>EOF\n");
         return true;
      }
      // If we don't match a certain amount of equal signs, we aren't eligible to close.  That amount can be 0.
      bool should_look_for_end = true;
      printf("closing signs: %d\n", scanner->level);
      for (uint32_t i = 0; i < scanner->level; i++) {
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
        return true;
      }
    } else {
      // consume everything if we aren't potentially ending
      advance(lexer);
    }
  }
}

static bool scan_ending(Scanner *scanner, TSLexer *lexer) {
  ADVANCE_OR_FALSE(lexer, ']')
  for (uint32_t i = 0; i < scanner->level; i++) {
    if (lexer->lookahead != '=') {
      return false;
    }
    advance(lexer);
    if (lexer->eof(lexer)) {
       return false;
    }
  }
  ADVANCE_OR_FALSE(lexer, ']')
  reset(scanner);
  return true;
}

static bool scan_string_block(TSLexer *lexer) {
  printf("scan_string_block>top\n");
  ADVANCE_OR_FALSE(lexer, '[')
  uint32_t closing_signs = 0;
  if (lexer->lookahead == '=') {
    for (;;) {
      advance(lexer);
      closing_signs++;
      if (lexer->eof(lexer)) {
        printf("scan_string_block_starm>Found EOF in = check\n");
        return false;
      }
      if (lexer->lookahead != '=') {
        printf("scan_string_block>Header has finished counting equal signs: %d total\n", closing_signs);
        break;
      }
    }
  }
  ADVANCE_OR_FALSE(lexer, '[')
  // start capturing content
  for (;;) {
    if (lexer->eof(lexer)) {
      // I think we return false here, unless it feels nicer to highlight as a string.
      return false;
    }
    if (lexer->lookahead == ']') {
      advance(lexer);
      // check to see if this is the ending
      uint32_t found_closing_signs = 0;
      for (;;) {
        printf("string_block>At possible end found closing: %d vs actual closing %d\n", found_closing_signs, closing_signs);
        if (lexer->lookahead == ']') {
          if (found_closing_signs != closing_signs) {
            printf("string_block>Found second ] without matching enough signs\n");
            // reset any closing signs we have already found, as this ] could be the actual start of the end
            found_closing_signs = 0;
            advance(lexer);
            continue;
          } else {
            // We have a valid ending now, we can consume and return
            printf("string_block>Successfully closing string block");
            advance(lexer);
            return true;
          }
        }
        if (lexer->eof(lexer)) {
          return false;
        }
        // We're not a closing sign and we're not an equal sign, so we just 
        // keep going as string block content (breaking the inner loop)
        if (lexer->lookahead != '=') {
          advance(lexer);
          break;
        }

        // We are an equal sign, we keep adding to the found closing signs
        found_closing_signs++;
        advance(lexer);
      }
    } else {
      // we're not at a potential stop, so we can just advance as you can put 
      // anything else inside a string block
      advance(lexer);
    }
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
  // if (valid_symbols[SHORT_COMMENT]) {
  //   printf("Valid: Short Comment\n");
  // }
  // if (valid_symbols[LONG_COMMENT]) {
  //   printf("Valid: Long Comment\n");
  // }

  skip_whitespace(lexer);

  if (lexer->lookahead == '-' && valid_symbols[SHORT_COMMENT_START] && valid_symbols[LONG_COMMENT_START]) {
    printf("In SHORT_COMMENT/LONG_COMMENT main branch\n");
    lexer->result_symbol = SHORT_COMMENT_START;
    return scan_comment_start(scanner, lexer);
  }

  if (lexer->lookahead == '#' && valid_symbols[SHORT_PP_START] && valid_symbols[LONG_PP_START]) {
    printf("In PP_START main branch\n");
    lexer->result_symbol = SHORT_PP_START;
    return scan_pp_start(scanner, lexer);
  }

  // --- Bodies -------------
  if (valid_symbols[LONG_COMMENT_BODY]) {
    printf("In LONG_COMMENT_BODY main branch\n");
    lexer->result_symbol = LONG_COMMENT_BODY;
    return scan_body(scanner, lexer);
  }

  if (valid_symbols[LONG_PP_BODY]) {
    printf("In LONG_PP_BODY main branch\n");
    lexer->result_symbol = LONG_PP_BODY;
    return scan_body(scanner, lexer);
  }
  // ------------------------

  // --- Endings ------------
  if (valid_symbols[LONG_COMMENT_END]) {
    printf("In LONG_COMMENT_END main branch\n");
    lexer->result_symbol = LONG_COMMENT_END;
    return scan_ending(scanner, lexer);
  }

  if (valid_symbols[LONG_PP_END]) {
    printf("In LONG_PP_END main branch\n");
    lexer->result_symbol = LONG_PP_END;
    return scan_ending(scanner, lexer);
  }
  // ------------------------

  // For now, string blocks will remain stateless, as we don't need 
  // to differentiate between start, body, and end. If this 
  // becomes necessary, we can refactor.
  if (lexer->lookahead == '[' && valid_symbols[STRING_BLOCK]) {
    printf("In STRING_BLOCK\n");
    lexer->result_symbol = STRING_BLOCK;
    return scan_string_block(lexer);
  }

  printf("external scanner> Falling through to return false\n");
  return false;
}
 
