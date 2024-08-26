// TODO: Backup this file and rebuild it, testing that it works step by step.
#include "tree_sitter/parser.h"
#include "tree_sitter/alloc.h"

#include <assert.h>
#include <string.h>
#include <wctype.h>

enum TokenType {
  SHORT_COMMENT,
  LONG_COMMENT_START,
  // LONG_COMMENT_CONTENT,
  LONG_COMMENT_END,
};

// Each '=' sign found increases the level by one.
// --[[ : level 0
// --[=[ : level 1
// --[==[ : level 2
typedef struct {
  uint8_t level;
} Scanner;

// We'll be matching several opening characters or bailing, so this is a small convenience macro.
// if (lexer->lookahead == given_char) { advance(lexer) } else { return false; }
#define ADVANCE_OR_FALSE(lexer, given_char) \
  if ((lexer)->lookahead == (given_char)) { \
    advance(lexer); \
  } else { \
    return false; \
  }

static inline void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

static inline void skip(TSLexer *lexer) { lexer->advance(lexer, true); }

static inline void reset(Scanner *scanner) {
  scanner->level = 0;
}

void* tree_sitter_neluablk_external_scanner_create() {
  Scanner *scanner = (Scanner *)ts_calloc(1, sizeof(Scanner));
  memset(scanner, 0, sizeof(Scanner));
  return scanner;
}

void tree_sitter_neluablk_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  ts_free(scanner);
}

unsigned tree_sitter_neluablk_external_scanner_serialize
(void *payload, char *buffer) {
  Scanner *scanner = (Scanner *)payload;
  *buffer = scanner->level; 
  return 1;
}

void tree_sitter_neluablk_external_scanner_deserialize
(void *payload, char *buffer, unsigned length) {
  assert(length >= 0 && length < 2 && "Invalid scanner length received by deserialize, expected 1");
  Scanner *scanner = (Scanner *)payload;
  scanner->level = *buffer;
}

static bool scan_short_comment(TSLexer *lexer) {
  ADVANCE_OR_FALSE(lexer, '-')
  ADVANCE_OR_FALSE(lexer, '-')

  // We have a possible long comment that we want to exit on
  if (lexer->lookahead == '[') {
    // Advance past all equal signs
    for (;;) {
      // TODO: Check EOF
      if (lexer->eof(lexer)) {
        return false;
      }
      if (lexer->lookahead != '=') {
        break;
      }
      advance(lexer);
    }

    if (lexer->lookahead == '[') {
      // We are a long comment, abort
      return false;
    }
  }

  // Now we skip everything until a line break 
  for (;;) {
    if (lexer->eof(lexer)) {
      return true;
    }
    if (lexer->lookahead != '\n' && lexer->lookahead != '\r') {
      advance(lexer);
    } else {
      return true;
    }
  }
   
}

// static bool scan_long_comment_start(Scanner *scanner, TSLexer *lexer) {
  // We're looking for the opening, --[[
  // We must start with at least --[

  ADVANCE_OR_FALSE(lexer, '-')
  ADVANCE_OR_FALSE(lexer, '-')
  ADVANCE_OR_FALSE(lexer, '[')
  ADVANCE_OR_FALSE(lexer, '[')
  return true;
  // for (;;) {
  //   if (lexer->eof(lexer)) {
  //     return false;
  //   }
}

static bool scan_long_comment_end(Scanner *scanner, TSLexer *lexer) {
  // We're looking for the opening, --[[
  // We must start with at least --[

  ADVANCE_OR_FALSE(lexer, ']')
  ADVANCE_OR_FALSE(lexer, ']')
  return true;
  // for (;;) {
  //   if (lexer->eof(lexer)) {
  //     return false;
  //   }
}

bool tree_sitter_neluablk_external_scanner_scan 
(void *payload, TSLexer *lexer, const bool *valid_symbols) {
  Scanner *scanner = (Scanner *)payload;
  if (valid_symbols[LONG_COMMENT_START] && valid_symbols[LONG_COMMENT_END]) {
    // We're in error recovery
    return false;
  }

  if (valid_symbols[SHORT_COMMENT]) {
    lexer->result_symbol = SHORT_COMMENT;
    return scan_short_comment(lexer);
  }

  if (valid_symbols[LONG_COMMENT_START]) {
    lexer->result_symbol = LONG_COMMENT_START;
    return scan_long_comment_start(scanner, lexer);
  }

  if (valid_symbols[LONG_COMMENT_END]) {
    lexer->result_symbol = LONG_COMMENT_END;
    return scan_long_comment_end(scanner, lexer);
  }
  return false;
}

// It will be pretty important to define areas that we specifically times we should not be scanning for certain things

