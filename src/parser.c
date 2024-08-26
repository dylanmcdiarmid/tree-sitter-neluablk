#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 74
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 109
#define ALIAS_COUNT 0
#define TOKEN_COUNT 80
#define EXTERNAL_TOKEN_COUNT 10
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 3

enum ts_symbol_identifiers {
  anon_sym_COLON_COLON = 1,
  anon_sym_COMMA = 2,
  anon_sym_or = 3,
  anon_sym_and = 4,
  anon_sym_not = 5,
  anon_sym_DASH = 6,
  anon_sym_POUND = 7,
  anon_sym_TILDE = 8,
  anon_sym_AMP = 9,
  anon_sym_DOLLAR = 10,
  aux_sym__hex_number_token1 = 11,
  aux_sym__bin_number_token1 = 12,
  aux_sym__exponent_e_token1 = 13,
  aux_sym__exponent_p_token1 = 14,
  aux_sym__dec_prefix_token1 = 15,
  anon_sym_DOT = 16,
  aux_sym__dec_prefix_token2 = 17,
  aux_sym__hex_prefix_token1 = 18,
  aux_sym__hex_prefix_token2 = 19,
  aux_sym__bin_prefix_token1 = 20,
  aux_sym__bin_prefix_token2 = 21,
  sym__exp_digits = 22,
  anon_sym__ = 23,
  anon_sym_i = 24,
  anon_sym_integer = 25,
  anon_sym_u = 26,
  anon_sym_uinteger = 27,
  anon_sym_n = 28,
  anon_sym_number = 29,
  anon_sym_b = 30,
  anon_sym_byte = 31,
  anon_sym_is = 32,
  anon_sym_isize = 33,
  anon_sym_i8 = 34,
  anon_sym_int8 = 35,
  anon_sym_i16 = 36,
  anon_sym_int16 = 37,
  anon_sym_i32 = 38,
  anon_sym_int32 = 39,
  anon_sym_i64 = 40,
  anon_sym_int64 = 41,
  anon_sym_i128 = 42,
  anon_sym_int128 = 43,
  anon_sym_us = 44,
  anon_sym_usize = 45,
  anon_sym_u8 = 46,
  anon_sym_uint8 = 47,
  anon_sym_u16 = 48,
  anon_sym_uint16 = 49,
  anon_sym_u32 = 50,
  anon_sym_uint32 = 51,
  anon_sym_u64 = 52,
  anon_sym_uint64 = 53,
  anon_sym_u128 = 54,
  anon_sym_uint128 = 55,
  anon_sym_f32 = 56,
  anon_sym_float32 = 57,
  anon_sym_f64 = 58,
  anon_sym_float64 = 59,
  anon_sym_f128 = 60,
  anon_sym_float128 = 61,
  anon_sym_DQUOTE = 62,
  anon_sym_SQUOTE = 63,
  sym_unescaped_single_string_fragment = 64,
  sym_unescaped_double_string_fragment = 65,
  sym_escape_sequence = 66,
  aux_sym_short_pp_body_token1 = 67,
  sym__name_prefix = 68,
  sym__name_suffix = 69,
  sym_short_comment_start = 70,
  sym_long_comment_start = 71,
  sym_long_comment_body = 72,
  sym_long_comment_end = 73,
  sym_string_block = 74,
  sym_short_pp_start = 75,
  sym_long_pp_start = 76,
  sym_long_pp_body = 77,
  sym_long_pp_end = 78,
  sym_ERROR_SENTINEL = 79,
  sym_source_file = 80,
  sym_Block = 81,
  sym_Label = 82,
  sym_expression = 83,
  sym_binary_expression = 84,
  sym_unary_expression = 85,
  sym_simple_expression = 86,
  sym_Number = 87,
  sym__dec_number = 88,
  sym__hex_number = 89,
  sym__bin_number = 90,
  sym__exponent_e = 91,
  sym__exponent_p = 92,
  sym__dec_prefix = 93,
  sym__hex_prefix = 94,
  sym__bin_prefix = 95,
  sym_number_type_decl = 96,
  sym_String = 97,
  sym_comment = 98,
  sym_short_pp = 99,
  sym_short_pp_body = 100,
  sym_long_pp = 101,
  sym_short_comment = 102,
  sym_short_comment_body = 103,
  sym_long_comment = 104,
  sym_Name = 105,
  aux_sym_source_file_repeat1 = 106,
  aux_sym_String_repeat1 = 107,
  aux_sym_String_repeat2 = 108,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COLON_COLON] = "::",
  [anon_sym_COMMA] = ",",
  [anon_sym_or] = "or",
  [anon_sym_and] = "and",
  [anon_sym_not] = "not",
  [anon_sym_DASH] = "-",
  [anon_sym_POUND] = "#",
  [anon_sym_TILDE] = "~",
  [anon_sym_AMP] = "&",
  [anon_sym_DOLLAR] = "$",
  [aux_sym__hex_number_token1] = "_hex_number_token1",
  [aux_sym__bin_number_token1] = "_bin_number_token1",
  [aux_sym__exponent_e_token1] = "_exponent_e_token1",
  [aux_sym__exponent_p_token1] = "_exponent_p_token1",
  [aux_sym__dec_prefix_token1] = "_dec_prefix_token1",
  [anon_sym_DOT] = ".",
  [aux_sym__dec_prefix_token2] = "_dec_prefix_token2",
  [aux_sym__hex_prefix_token1] = "_hex_prefix_token1",
  [aux_sym__hex_prefix_token2] = "_hex_prefix_token2",
  [aux_sym__bin_prefix_token1] = "_bin_prefix_token1",
  [aux_sym__bin_prefix_token2] = "_bin_prefix_token2",
  [sym__exp_digits] = "exponent",
  [anon_sym__] = "_",
  [anon_sym_i] = "i",
  [anon_sym_integer] = "integer",
  [anon_sym_u] = "u",
  [anon_sym_uinteger] = "uinteger",
  [anon_sym_n] = "n",
  [anon_sym_number] = "number",
  [anon_sym_b] = "b",
  [anon_sym_byte] = "byte",
  [anon_sym_is] = "is",
  [anon_sym_isize] = "isize",
  [anon_sym_i8] = "i8",
  [anon_sym_int8] = "int8",
  [anon_sym_i16] = "i16",
  [anon_sym_int16] = "int16",
  [anon_sym_i32] = "i32",
  [anon_sym_int32] = "int32",
  [anon_sym_i64] = "i64",
  [anon_sym_int64] = "int64",
  [anon_sym_i128] = "i128",
  [anon_sym_int128] = "int128",
  [anon_sym_us] = "us",
  [anon_sym_usize] = "usize",
  [anon_sym_u8] = "u8",
  [anon_sym_uint8] = "uint8",
  [anon_sym_u16] = "u16",
  [anon_sym_uint16] = "uint16",
  [anon_sym_u32] = "u32",
  [anon_sym_uint32] = "uint32",
  [anon_sym_u64] = "u64",
  [anon_sym_uint64] = "uint64",
  [anon_sym_u128] = "u128",
  [anon_sym_uint128] = "uint128",
  [anon_sym_f32] = "f32",
  [anon_sym_float32] = "float32",
  [anon_sym_f64] = "f64",
  [anon_sym_float64] = "float64",
  [anon_sym_f128] = "f128",
  [anon_sym_float128] = "float128",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SQUOTE] = "'",
  [sym_unescaped_single_string_fragment] = "string_fragment",
  [sym_unescaped_double_string_fragment] = "string_fragment",
  [sym_escape_sequence] = "escape_sequence",
  [aux_sym_short_pp_body_token1] = "short_pp_body_token1",
  [sym__name_prefix] = "_name_prefix",
  [sym__name_suffix] = "_name_suffix",
  [sym_short_comment_start] = "short_comment_start",
  [sym_long_comment_start] = "long_comment_start",
  [sym_long_comment_body] = "long_comment_body",
  [sym_long_comment_end] = "long_comment_end",
  [sym_string_block] = "string_block",
  [sym_short_pp_start] = "short_pp_start",
  [sym_long_pp_start] = "long_pp_start",
  [sym_long_pp_body] = "long_pp_body",
  [sym_long_pp_end] = "long_pp_end",
  [sym_ERROR_SENTINEL] = "ERROR_SENTINEL",
  [sym_source_file] = "source_file",
  [sym_Block] = "Block",
  [sym_Label] = "Label",
  [sym_expression] = "expression",
  [sym_binary_expression] = "binary_expression",
  [sym_unary_expression] = "unary_expression",
  [sym_simple_expression] = "simple_expression",
  [sym_Number] = "Number",
  [sym__dec_number] = "_dec_number",
  [sym__hex_number] = "_hex_number",
  [sym__bin_number] = "_bin_number",
  [sym__exponent_e] = "_exponent_e",
  [sym__exponent_p] = "_exponent_p",
  [sym__dec_prefix] = "dec_number",
  [sym__hex_prefix] = "hex_number",
  [sym__bin_prefix] = "bin_number",
  [sym_number_type_decl] = "number_type_decl",
  [sym_String] = "String",
  [sym_comment] = "comment",
  [sym_short_pp] = "short_pp",
  [sym_short_pp_body] = "short_pp_body",
  [sym_long_pp] = "long_pp",
  [sym_short_comment] = "short_comment",
  [sym_short_comment_body] = "short_comment_body",
  [sym_long_comment] = "long_comment",
  [sym_Name] = "Name",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_String_repeat1] = "String_repeat1",
  [aux_sym_String_repeat2] = "String_repeat2",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_or] = anon_sym_or,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_not] = anon_sym_not,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [aux_sym__hex_number_token1] = aux_sym__hex_number_token1,
  [aux_sym__bin_number_token1] = aux_sym__bin_number_token1,
  [aux_sym__exponent_e_token1] = aux_sym__exponent_e_token1,
  [aux_sym__exponent_p_token1] = aux_sym__exponent_p_token1,
  [aux_sym__dec_prefix_token1] = aux_sym__dec_prefix_token1,
  [anon_sym_DOT] = anon_sym_DOT,
  [aux_sym__dec_prefix_token2] = aux_sym__dec_prefix_token2,
  [aux_sym__hex_prefix_token1] = aux_sym__hex_prefix_token1,
  [aux_sym__hex_prefix_token2] = aux_sym__hex_prefix_token2,
  [aux_sym__bin_prefix_token1] = aux_sym__bin_prefix_token1,
  [aux_sym__bin_prefix_token2] = aux_sym__bin_prefix_token2,
  [sym__exp_digits] = sym__exp_digits,
  [anon_sym__] = anon_sym__,
  [anon_sym_i] = anon_sym_i,
  [anon_sym_integer] = anon_sym_integer,
  [anon_sym_u] = anon_sym_u,
  [anon_sym_uinteger] = anon_sym_uinteger,
  [anon_sym_n] = anon_sym_n,
  [anon_sym_number] = anon_sym_number,
  [anon_sym_b] = anon_sym_b,
  [anon_sym_byte] = anon_sym_byte,
  [anon_sym_is] = anon_sym_is,
  [anon_sym_isize] = anon_sym_isize,
  [anon_sym_i8] = anon_sym_i8,
  [anon_sym_int8] = anon_sym_int8,
  [anon_sym_i16] = anon_sym_i16,
  [anon_sym_int16] = anon_sym_int16,
  [anon_sym_i32] = anon_sym_i32,
  [anon_sym_int32] = anon_sym_int32,
  [anon_sym_i64] = anon_sym_i64,
  [anon_sym_int64] = anon_sym_int64,
  [anon_sym_i128] = anon_sym_i128,
  [anon_sym_int128] = anon_sym_int128,
  [anon_sym_us] = anon_sym_us,
  [anon_sym_usize] = anon_sym_usize,
  [anon_sym_u8] = anon_sym_u8,
  [anon_sym_uint8] = anon_sym_uint8,
  [anon_sym_u16] = anon_sym_u16,
  [anon_sym_uint16] = anon_sym_uint16,
  [anon_sym_u32] = anon_sym_u32,
  [anon_sym_uint32] = anon_sym_uint32,
  [anon_sym_u64] = anon_sym_u64,
  [anon_sym_uint64] = anon_sym_uint64,
  [anon_sym_u128] = anon_sym_u128,
  [anon_sym_uint128] = anon_sym_uint128,
  [anon_sym_f32] = anon_sym_f32,
  [anon_sym_float32] = anon_sym_float32,
  [anon_sym_f64] = anon_sym_f64,
  [anon_sym_float64] = anon_sym_float64,
  [anon_sym_f128] = anon_sym_f128,
  [anon_sym_float128] = anon_sym_float128,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym_unescaped_single_string_fragment] = sym_unescaped_single_string_fragment,
  [sym_unescaped_double_string_fragment] = sym_unescaped_single_string_fragment,
  [sym_escape_sequence] = sym_escape_sequence,
  [aux_sym_short_pp_body_token1] = aux_sym_short_pp_body_token1,
  [sym__name_prefix] = sym__name_prefix,
  [sym__name_suffix] = sym__name_suffix,
  [sym_short_comment_start] = sym_short_comment_start,
  [sym_long_comment_start] = sym_long_comment_start,
  [sym_long_comment_body] = sym_long_comment_body,
  [sym_long_comment_end] = sym_long_comment_end,
  [sym_string_block] = sym_string_block,
  [sym_short_pp_start] = sym_short_pp_start,
  [sym_long_pp_start] = sym_long_pp_start,
  [sym_long_pp_body] = sym_long_pp_body,
  [sym_long_pp_end] = sym_long_pp_end,
  [sym_ERROR_SENTINEL] = sym_ERROR_SENTINEL,
  [sym_source_file] = sym_source_file,
  [sym_Block] = sym_Block,
  [sym_Label] = sym_Label,
  [sym_expression] = sym_expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym_unary_expression] = sym_unary_expression,
  [sym_simple_expression] = sym_simple_expression,
  [sym_Number] = sym_Number,
  [sym__dec_number] = sym__dec_number,
  [sym__hex_number] = sym__hex_number,
  [sym__bin_number] = sym__bin_number,
  [sym__exponent_e] = sym__exponent_e,
  [sym__exponent_p] = sym__exponent_p,
  [sym__dec_prefix] = sym__dec_prefix,
  [sym__hex_prefix] = sym__hex_prefix,
  [sym__bin_prefix] = sym__bin_prefix,
  [sym_number_type_decl] = sym_number_type_decl,
  [sym_String] = sym_String,
  [sym_comment] = sym_comment,
  [sym_short_pp] = sym_short_pp,
  [sym_short_pp_body] = sym_short_pp_body,
  [sym_long_pp] = sym_long_pp,
  [sym_short_comment] = sym_short_comment,
  [sym_short_comment_body] = sym_short_comment_body,
  [sym_long_comment] = sym_long_comment,
  [sym_Name] = sym_Name,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_String_repeat1] = aux_sym_String_repeat1,
  [aux_sym_String_repeat2] = aux_sym_String_repeat2,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_COLON_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_or] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_not] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__hex_number_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__bin_number_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__exponent_e_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__exponent_p_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__dec_prefix_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__dec_prefix_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__hex_prefix_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__hex_prefix_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__bin_prefix_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__bin_prefix_token2] = {
    .visible = false,
    .named = false,
  },
  [sym__exp_digits] = {
    .visible = true,
    .named = true,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_integer] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uinteger] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_n] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_number] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_b] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_byte] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_is] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_isize] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_i128] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int128] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_us] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_usize] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uint8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uint16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uint32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uint64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u128] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uint128] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_f32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_f64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_f128] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float128] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_unescaped_single_string_fragment] = {
    .visible = true,
    .named = true,
  },
  [sym_unescaped_double_string_fragment] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_short_pp_body_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__name_prefix] = {
    .visible = false,
    .named = true,
  },
  [sym__name_suffix] = {
    .visible = false,
    .named = true,
  },
  [sym_short_comment_start] = {
    .visible = true,
    .named = true,
  },
  [sym_long_comment_start] = {
    .visible = true,
    .named = true,
  },
  [sym_long_comment_body] = {
    .visible = true,
    .named = true,
  },
  [sym_long_comment_end] = {
    .visible = true,
    .named = true,
  },
  [sym_string_block] = {
    .visible = true,
    .named = true,
  },
  [sym_short_pp_start] = {
    .visible = true,
    .named = true,
  },
  [sym_long_pp_start] = {
    .visible = true,
    .named = true,
  },
  [sym_long_pp_body] = {
    .visible = true,
    .named = true,
  },
  [sym_long_pp_end] = {
    .visible = true,
    .named = true,
  },
  [sym_ERROR_SENTINEL] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_Block] = {
    .visible = true,
    .named = true,
  },
  [sym_Label] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_simple_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_Number] = {
    .visible = true,
    .named = true,
  },
  [sym__dec_number] = {
    .visible = false,
    .named = true,
  },
  [sym__hex_number] = {
    .visible = false,
    .named = true,
  },
  [sym__bin_number] = {
    .visible = false,
    .named = true,
  },
  [sym__exponent_e] = {
    .visible = false,
    .named = true,
  },
  [sym__exponent_p] = {
    .visible = false,
    .named = true,
  },
  [sym__dec_prefix] = {
    .visible = true,
    .named = true,
  },
  [sym__hex_prefix] = {
    .visible = true,
    .named = true,
  },
  [sym__bin_prefix] = {
    .visible = true,
    .named = true,
  },
  [sym_number_type_decl] = {
    .visible = true,
    .named = true,
  },
  [sym_String] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_short_pp] = {
    .visible = true,
    .named = true,
  },
  [sym_short_pp_body] = {
    .visible = true,
    .named = true,
  },
  [sym_long_pp] = {
    .visible = true,
    .named = true,
  },
  [sym_short_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_short_comment_body] = {
    .visible = true,
    .named = true,
  },
  [sym_long_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_Name] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_String_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_String_repeat2] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_argument = 1,
  field_left = 2,
  field_operator = 3,
  field_right = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_argument] = "argument",
  [field_left] = "left",
  [field_operator] = "operator",
  [field_right] = "right",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_argument, 1},
    {field_operator, 0},
  [2] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(74);
      ADVANCE_MAP(
        '"', 140,
        '#', 81,
        '$', 84,
        '&', 83,
        '\'', 141,
        ',', 76,
        '-', 80,
        '.', 93,
        '0', 89,
        '1', 91,
        ':', 37,
        '\\', 1,
        '_', 97,
        'b', 107,
        'i', 98,
        'n', 104,
        'u', 101,
        '~', 82,
        'E', 87,
        'e', 87,
        'P', 88,
        'p', 88,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(72);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(92);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0x80 <= lookahead && lookahead <= 0xbf) ||
          (0xc2 <= lookahead && lookahead <= 0xfd)) ADVANCE(157);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(149);
      if (lookahead == '\r') ADVANCE(147);
      if (lookahead == 'u') ADVANCE(65);
      if (lookahead == 'x') ADVANCE(71);
      if (lookahead == 'z') ADVANCE(148);
      if (('0' <= lookahead && lookahead <= '2')) ADVANCE(151);
      if (lookahead == '\\' ||
          lookahead == 'a' ||
          lookahead == 'b' ||
          lookahead == 'f' ||
          lookahead == 'r' ||
          ('t' <= lookahead && lookahead <= 'v')) ADVANCE(146);
      if (('3' <= lookahead && lookahead <= '9')) ADVANCE(152);
      END_STATE();
    case 2:
      if (lookahead == '\r') ADVANCE(156);
      if (lookahead == '\\') ADVANCE(153);
      if (lookahead != 0) ADVANCE(155);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(140);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(4);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(144);
      if (lookahead != 0) ADVANCE(145);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(140);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      END_STATE();
    case 5:
      if (lookahead == '\'') ADVANCE(141);
      if (lookahead == '\\') ADVANCE(1);
      if (lookahead == '\n' ||
          lookahead == '\r') SKIP(6);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(142);
      if (lookahead != 0) ADVANCE(143);
      END_STATE();
    case 6:
      if (lookahead == '\'') ADVANCE(141);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      END_STATE();
    case 7:
      if (lookahead == '.') ADVANCE(93);
      if (lookahead == 'b') ADVANCE(108);
      if (lookahead == 'f') ADVANCE(9);
      if (lookahead == 'i') ADVANCE(99);
      if (lookahead == 'n') ADVANCE(105);
      if (lookahead == 'u') ADVANCE(102);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(95);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      END_STATE();
    case 8:
      if (lookahead == '.') ADVANCE(93);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(94);
      END_STATE();
    case 9:
      if (lookahead == '1') ADVANCE(13);
      if (lookahead == '3') ADVANCE(14);
      if (lookahead == '6') ADVANCE(25);
      if (lookahead == 'l') ADVANCE(53);
      END_STATE();
    case 10:
      if (lookahead == '1') ADVANCE(22);
      if (lookahead == '3') ADVANCE(17);
      if (lookahead == '6') ADVANCE(28);
      if (lookahead == '8') ADVANCE(113);
      if (lookahead == 'e') ADVANCE(47);
      END_STATE();
    case 11:
      if (lookahead == '1') ADVANCE(23);
      if (lookahead == '3') ADVANCE(18);
      if (lookahead == '6') ADVANCE(29);
      if (lookahead == '8') ADVANCE(125);
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 12:
      if (lookahead == '1') ADVANCE(24);
      if (lookahead == '3') ADVANCE(19);
      if (lookahead == '6') ADVANCE(30);
      END_STATE();
    case 13:
      if (lookahead == '2') ADVANCE(31);
      END_STATE();
    case 14:
      if (lookahead == '2') ADVANCE(134);
      END_STATE();
    case 15:
      if (lookahead == '2') ADVANCE(116);
      END_STATE();
    case 16:
      if (lookahead == '2') ADVANCE(128);
      END_STATE();
    case 17:
      if (lookahead == '2') ADVANCE(117);
      END_STATE();
    case 18:
      if (lookahead == '2') ADVANCE(129);
      END_STATE();
    case 19:
      if (lookahead == '2') ADVANCE(135);
      END_STATE();
    case 20:
      if (lookahead == '2') ADVANCE(32);
      if (lookahead == '6') ADVANCE(114);
      END_STATE();
    case 21:
      if (lookahead == '2') ADVANCE(33);
      if (lookahead == '6') ADVANCE(126);
      END_STATE();
    case 22:
      if (lookahead == '2') ADVANCE(34);
      if (lookahead == '6') ADVANCE(115);
      END_STATE();
    case 23:
      if (lookahead == '2') ADVANCE(35);
      if (lookahead == '6') ADVANCE(127);
      END_STATE();
    case 24:
      if (lookahead == '2') ADVANCE(36);
      END_STATE();
    case 25:
      if (lookahead == '4') ADVANCE(136);
      END_STATE();
    case 26:
      if (lookahead == '4') ADVANCE(118);
      END_STATE();
    case 27:
      if (lookahead == '4') ADVANCE(130);
      END_STATE();
    case 28:
      if (lookahead == '4') ADVANCE(119);
      END_STATE();
    case 29:
      if (lookahead == '4') ADVANCE(131);
      END_STATE();
    case 30:
      if (lookahead == '4') ADVANCE(137);
      END_STATE();
    case 31:
      if (lookahead == '8') ADVANCE(138);
      END_STATE();
    case 32:
      if (lookahead == '8') ADVANCE(120);
      END_STATE();
    case 33:
      if (lookahead == '8') ADVANCE(132);
      END_STATE();
    case 34:
      if (lookahead == '8') ADVANCE(121);
      END_STATE();
    case 35:
      if (lookahead == '8') ADVANCE(133);
      END_STATE();
    case 36:
      if (lookahead == '8') ADVANCE(139);
      END_STATE();
    case 37:
      if (lookahead == ':') ADVANCE(75);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(61);
      END_STATE();
    case 39:
      if (lookahead == 'b') ADVANCE(44);
      END_STATE();
    case 40:
      if (lookahead == 'd') ADVANCE(78);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(109);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(111);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(123);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(55);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(56);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(57);
      END_STATE();
    case 47:
      if (lookahead == 'g') ADVANCE(45);
      END_STATE();
    case 48:
      if (lookahead == 'g') ADVANCE(46);
      END_STATE();
    case 49:
      if (lookahead == 'm') ADVANCE(39);
      END_STATE();
    case 50:
      if (lookahead == 'n') ADVANCE(40);
      END_STATE();
    case 51:
      if (lookahead == 'n') ADVANCE(62);
      END_STATE();
    case 52:
      if (lookahead == 'o') ADVANCE(58);
      END_STATE();
    case 53:
      if (lookahead == 'o') ADVANCE(38);
      END_STATE();
    case 54:
      if (lookahead == 'r') ADVANCE(77);
      END_STATE();
    case 55:
      if (lookahead == 'r') ADVANCE(106);
      END_STATE();
    case 56:
      if (lookahead == 'r') ADVANCE(100);
      END_STATE();
    case 57:
      if (lookahead == 'r') ADVANCE(103);
      END_STATE();
    case 58:
      if (lookahead == 't') ADVANCE(79);
      END_STATE();
    case 59:
      if (lookahead == 't') ADVANCE(41);
      END_STATE();
    case 60:
      if (lookahead == 't') ADVANCE(10);
      END_STATE();
    case 61:
      if (lookahead == 't') ADVANCE(12);
      END_STATE();
    case 62:
      if (lookahead == 't') ADVANCE(11);
      END_STATE();
    case 63:
      if (lookahead == 'z') ADVANCE(42);
      END_STATE();
    case 64:
      if (lookahead == 'z') ADVANCE(43);
      END_STATE();
    case 65:
      if (lookahead == '{') ADVANCE(70);
      END_STATE();
    case 66:
      if (lookahead == '}') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(66);
      END_STATE();
    case 67:
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(68);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(67);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0x80 <= lookahead && lookahead <= 0xbf) ||
          (0xc2 <= lookahead && lookahead <= 0xfd)) ADVANCE(157);
      END_STATE();
    case 68:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      END_STATE();
    case 69:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(146);
      END_STATE();
    case 70:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(66);
      END_STATE();
    case 71:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(69);
      END_STATE();
    case 72:
      if (eof) ADVANCE(74);
      ADVANCE_MAP(
        '"', 140,
        '#', 81,
        '$', 84,
        '&', 83,
        '\'', 141,
        ',', 76,
        '-', 80,
        '.', 93,
        '0', 89,
        '1', 91,
        ':', 37,
        '_', 97,
        'b', 107,
        'i', 98,
        'n', 104,
        'u', 101,
        '~', 82,
        'E', 87,
        'e', 87,
        'P', 88,
        'p', 88,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(72);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(92);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0x80 <= lookahead && lookahead <= 0xbf) ||
          (0xc2 <= lookahead && lookahead <= 0xfd)) ADVANCE(157);
      END_STATE();
    case 73:
      if (eof) ADVANCE(74);
      ADVANCE_MAP(
        '"', 140,
        '#', 81,
        '$', 84,
        '&', 83,
        '\'', 141,
        '-', 80,
        '.', 93,
        '0', 90,
        ':', 37,
        '_', 97,
        'a', 50,
        'n', 52,
        'o', 54,
        '~', 82,
        'E', 87,
        'e', 87,
        'P', 88,
        'p', 88,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(73);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(92);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_not);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym__hex_number_token1);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym__bin_number_token1);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym__exponent_e_token1);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym__exponent_p_token1);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym__dec_prefix_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(86);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(85);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(91);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(92);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym__dec_prefix_token1);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(86);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(85);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym__dec_prefix_token1);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(91);
      if (('2' <= lookahead && lookahead <= '9')) ADVANCE(92);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(aux_sym__dec_prefix_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(92);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(aux_sym__hex_prefix_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(94);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(aux_sym__bin_prefix_token1);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(95);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym__exp_digits);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(96);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_i);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_i);
      if (lookahead == '1') ADVANCE(20);
      if (lookahead == '3') ADVANCE(15);
      if (lookahead == '6') ADVANCE(26);
      if (lookahead == '8') ADVANCE(112);
      if (lookahead == 'n') ADVANCE(60);
      if (lookahead == 's') ADVANCE(110);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_integer);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_u);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_u);
      if (lookahead == '1') ADVANCE(21);
      if (lookahead == '3') ADVANCE(16);
      if (lookahead == '6') ADVANCE(27);
      if (lookahead == '8') ADVANCE(124);
      if (lookahead == 'i') ADVANCE(51);
      if (lookahead == 's') ADVANCE(122);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_uinteger);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_n);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_n);
      if (lookahead == 'u') ADVANCE(49);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_number);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_b);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_b);
      if (lookahead == 'y') ADVANCE(59);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_byte);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_is);
      if (lookahead == 'i') ADVANCE(63);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_isize);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_i8);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_int8);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_i16);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_int16);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_i32);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_int32);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_i64);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_int64);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_i128);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_int128);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_us);
      if (lookahead == 'i') ADVANCE(64);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_usize);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_u8);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_uint8);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_u16);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_uint16);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_u32);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_uint32);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_u64);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_uint64);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_u128);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_uint128);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_f32);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_float32);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_f64);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_float64);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_f128);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_float128);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_unescaped_single_string_fragment);
      if (lookahead == '\t' ||
          lookahead == 0x0b ||
          lookahead == '\f' ||
          lookahead == ' ') ADVANCE(142);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(143);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_unescaped_single_string_fragment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(143);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_unescaped_double_string_fragment);
      if (lookahead == '\t' ||
          lookahead == 0x0b ||
          lookahead == '\f' ||
          lookahead == ' ') ADVANCE(144);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(145);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_unescaped_double_string_fragment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(145);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (lookahead == '\n') ADVANCE(146);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (lookahead == '\r') ADVANCE(148);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(148);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (lookahead == '\r') ADVANCE(146);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '2')) ADVANCE(146);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '2')) ADVANCE(150);
      if (('3' <= lookahead && lookahead <= '9')) ADVANCE(146);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(146);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_short_pp_body_token1);
      if (lookahead == '\r') ADVANCE(156);
      if (lookahead == '\\') ADVANCE(153);
      if (lookahead != 0) ADVANCE(155);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_short_pp_body_token1);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(154);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(155);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_short_pp_body_token1);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(155);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_short_pp_body_token1);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead != 0) ADVANCE(155);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym__name_prefix);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym__name_suffix);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z') ||
          (0x80 <= lookahead && lookahead <= 0xbf) ||
          (0xc2 <= lookahead && lookahead <= 0xfd)) ADVANCE(158);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 73, .external_lex_state = 2},
  [2] = {.lex_state = 7},
  [3] = {.lex_state = 73, .external_lex_state = 2},
  [4] = {.lex_state = 73, .external_lex_state = 2},
  [5] = {.lex_state = 73, .external_lex_state = 2},
  [6] = {.lex_state = 73, .external_lex_state = 2},
  [7] = {.lex_state = 73, .external_lex_state = 2},
  [8] = {.lex_state = 73, .external_lex_state = 2},
  [9] = {.lex_state = 73, .external_lex_state = 2},
  [10] = {.lex_state = 73, .external_lex_state = 2},
  [11] = {.lex_state = 73, .external_lex_state = 2},
  [12] = {.lex_state = 73, .external_lex_state = 2},
  [13] = {.lex_state = 73, .external_lex_state = 2},
  [14] = {.lex_state = 73, .external_lex_state = 2},
  [15] = {.lex_state = 73, .external_lex_state = 2},
  [16] = {.lex_state = 73, .external_lex_state = 2},
  [17] = {.lex_state = 73, .external_lex_state = 2},
  [18] = {.lex_state = 73, .external_lex_state = 2},
  [19] = {.lex_state = 73, .external_lex_state = 2},
  [20] = {.lex_state = 73},
  [21] = {.lex_state = 73, .external_lex_state = 2},
  [22] = {.lex_state = 73, .external_lex_state = 2},
  [23] = {.lex_state = 73},
  [24] = {.lex_state = 73},
  [25] = {.lex_state = 73, .external_lex_state = 2},
  [26] = {.lex_state = 73, .external_lex_state = 2},
  [27] = {.lex_state = 73, .external_lex_state = 2},
  [28] = {.lex_state = 73, .external_lex_state = 2},
  [29] = {.lex_state = 73, .external_lex_state = 2},
  [30] = {.lex_state = 73, .external_lex_state = 2},
  [31] = {.lex_state = 73, .external_lex_state = 2},
  [32] = {.lex_state = 73, .external_lex_state = 2},
  [33] = {.lex_state = 73, .external_lex_state = 2},
  [34] = {.lex_state = 73, .external_lex_state = 2},
  [35] = {.lex_state = 73, .external_lex_state = 2},
  [36] = {.lex_state = 73, .external_lex_state = 2},
  [37] = {.lex_state = 73, .external_lex_state = 2},
  [38] = {.lex_state = 73, .external_lex_state = 2},
  [39] = {.lex_state = 73, .external_lex_state = 2},
  [40] = {.lex_state = 73, .external_lex_state = 2},
  [41] = {.lex_state = 73, .external_lex_state = 2},
  [42] = {.lex_state = 73, .external_lex_state = 2},
  [43] = {.lex_state = 73, .external_lex_state = 2},
  [44] = {.lex_state = 73, .external_lex_state = 2},
  [45] = {.lex_state = 73, .external_lex_state = 2},
  [46] = {.lex_state = 73, .external_lex_state = 2},
  [47] = {.lex_state = 73, .external_lex_state = 2},
  [48] = {.lex_state = 73, .external_lex_state = 2},
  [49] = {.lex_state = 73, .external_lex_state = 2},
  [50] = {.lex_state = 3},
  [51] = {.lex_state = 3},
  [52] = {.lex_state = 5},
  [53] = {.lex_state = 5},
  [54] = {.lex_state = 5},
  [55] = {.lex_state = 3},
  [56] = {.lex_state = 8},
  [57] = {.lex_state = 7},
  [58] = {.lex_state = 67},
  [59] = {.lex_state = 154},
  [60] = {.lex_state = 154},
  [61] = {.lex_state = 8},
  [62] = {.lex_state = 73},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 158},
  [66] = {.lex_state = 0, .external_lex_state = 3},
  [67] = {.lex_state = 0, .external_lex_state = 4},
  [68] = {.lex_state = 7},
  [69] = {.lex_state = 0, .external_lex_state = 5},
  [70] = {.lex_state = 0, .external_lex_state = 6},
  [71] = {.lex_state = 67},
  [72] = {.lex_state = 67},
  [73] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [aux_sym__hex_number_token1] = ACTIONS(1),
    [aux_sym__bin_number_token1] = ACTIONS(1),
    [aux_sym__exponent_e_token1] = ACTIONS(1),
    [aux_sym__exponent_p_token1] = ACTIONS(1),
    [aux_sym__dec_prefix_token1] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [aux_sym__bin_prefix_token1] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_i] = ACTIONS(1),
    [anon_sym_u] = ACTIONS(1),
    [anon_sym_n] = ACTIONS(1),
    [anon_sym_b] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
    [sym__name_prefix] = ACTIONS(1),
    [sym_short_comment_start] = ACTIONS(1),
    [sym_long_comment_start] = ACTIONS(1),
    [sym_long_comment_body] = ACTIONS(1),
    [sym_long_comment_end] = ACTIONS(1),
    [sym_string_block] = ACTIONS(1),
    [sym_short_pp_start] = ACTIONS(1),
    [sym_long_pp_start] = ACTIONS(1),
    [sym_long_pp_body] = ACTIONS(1),
    [sym_long_pp_end] = ACTIONS(1),
    [sym_ERROR_SENTINEL] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(73),
    [sym_Block] = STATE(4),
    [sym_Label] = STATE(41),
    [sym_expression] = STATE(25),
    [sym_binary_expression] = STATE(26),
    [sym_unary_expression] = STATE(26),
    [sym_simple_expression] = STATE(26),
    [sym_Number] = STATE(27),
    [sym__dec_number] = STATE(28),
    [sym__hex_number] = STATE(28),
    [sym__bin_number] = STATE(28),
    [sym__dec_prefix] = STATE(5),
    [sym_String] = STATE(27),
    [sym_comment] = STATE(41),
    [sym_short_pp] = STATE(41),
    [sym_long_pp] = STATE(41),
    [sym_short_comment] = STATE(48),
    [sym_long_comment] = STATE(48),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_COLON_COLON] = ACTIONS(5),
    [anon_sym_not] = ACTIONS(7),
    [anon_sym_DASH] = ACTIONS(7),
    [anon_sym_POUND] = ACTIONS(7),
    [anon_sym_TILDE] = ACTIONS(7),
    [anon_sym_AMP] = ACTIONS(7),
    [anon_sym_DOLLAR] = ACTIONS(7),
    [aux_sym__hex_number_token1] = ACTIONS(9),
    [aux_sym__bin_number_token1] = ACTIONS(11),
    [aux_sym__dec_prefix_token1] = ACTIONS(13),
    [anon_sym_DOT] = ACTIONS(15),
    [anon_sym_DQUOTE] = ACTIONS(17),
    [anon_sym_SQUOTE] = ACTIONS(19),
    [sym_short_comment_start] = ACTIONS(21),
    [sym_long_comment_start] = ACTIONS(23),
    [sym_string_block] = ACTIONS(25),
    [sym_short_pp_start] = ACTIONS(27),
    [sym_long_pp_start] = ACTIONS(29),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(31), 6,
      anon_sym_i,
      anon_sym_u,
      anon_sym_n,
      anon_sym_b,
      anon_sym_is,
      anon_sym_us,
    ACTIONS(33), 32,
      anon_sym_integer,
      anon_sym_uinteger,
      anon_sym_number,
      anon_sym_byte,
      anon_sym_isize,
      anon_sym_i8,
      anon_sym_int8,
      anon_sym_i16,
      anon_sym_int16,
      anon_sym_i32,
      anon_sym_int32,
      anon_sym_i64,
      anon_sym_int64,
      anon_sym_i128,
      anon_sym_int128,
      anon_sym_usize,
      anon_sym_u8,
      anon_sym_uint8,
      anon_sym_u16,
      anon_sym_uint16,
      anon_sym_u32,
      anon_sym_uint32,
      anon_sym_u64,
      anon_sym_uint64,
      anon_sym_u128,
      anon_sym_uint128,
      anon_sym_f32,
      anon_sym_float32,
      anon_sym_f64,
      anon_sym_float64,
      anon_sym_f128,
      anon_sym_float128,
  [43] = 22,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    ACTIONS(37), 1,
      anon_sym_COLON_COLON,
    ACTIONS(43), 1,
      aux_sym__hex_number_token1,
    ACTIONS(46), 1,
      aux_sym__bin_number_token1,
    ACTIONS(49), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(52), 1,
      anon_sym_DOT,
    ACTIONS(55), 1,
      anon_sym_DQUOTE,
    ACTIONS(58), 1,
      anon_sym_SQUOTE,
    ACTIONS(61), 1,
      sym_short_comment_start,
    ACTIONS(64), 1,
      sym_long_comment_start,
    ACTIONS(67), 1,
      sym_string_block,
    ACTIONS(70), 1,
      sym_short_pp_start,
    ACTIONS(73), 1,
      sym_long_pp_start,
    STATE(5), 1,
      sym__dec_prefix,
    STATE(25), 1,
      sym_expression,
    STATE(3), 2,
      sym_Block,
      aux_sym_source_file_repeat1,
    STATE(27), 2,
      sym_Number,
      sym_String,
    STATE(48), 2,
      sym_short_comment,
      sym_long_comment,
    STATE(26), 3,
      sym_binary_expression,
      sym_unary_expression,
      sym_simple_expression,
    STATE(28), 3,
      sym__dec_number,
      sym__hex_number,
      sym__bin_number,
    STATE(41), 4,
      sym_Label,
      sym_comment,
      sym_short_pp,
      sym_long_pp,
    ACTIONS(40), 6,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
  [125] = 22,
    ACTIONS(5), 1,
      anon_sym_COLON_COLON,
    ACTIONS(9), 1,
      aux_sym__hex_number_token1,
    ACTIONS(11), 1,
      aux_sym__bin_number_token1,
    ACTIONS(13), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(15), 1,
      anon_sym_DOT,
    ACTIONS(17), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_SQUOTE,
    ACTIONS(21), 1,
      sym_short_comment_start,
    ACTIONS(23), 1,
      sym_long_comment_start,
    ACTIONS(25), 1,
      sym_string_block,
    ACTIONS(27), 1,
      sym_short_pp_start,
    ACTIONS(29), 1,
      sym_long_pp_start,
    ACTIONS(76), 1,
      ts_builtin_sym_end,
    STATE(5), 1,
      sym__dec_prefix,
    STATE(25), 1,
      sym_expression,
    STATE(3), 2,
      sym_Block,
      aux_sym_source_file_repeat1,
    STATE(27), 2,
      sym_Number,
      sym_String,
    STATE(48), 2,
      sym_short_comment,
      sym_long_comment,
    STATE(26), 3,
      sym_binary_expression,
      sym_unary_expression,
      sym_simple_expression,
    STATE(28), 3,
      sym__dec_number,
      sym__hex_number,
      sym__bin_number,
    STATE(41), 4,
      sym_Label,
      sym_comment,
      sym_short_pp,
      sym_long_pp,
    ACTIONS(7), 6,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
  [207] = 6,
    ACTIONS(80), 1,
      aux_sym__exponent_e_token1,
    ACTIONS(82), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(84), 1,
      anon_sym__,
    STATE(17), 1,
      sym__exponent_e,
    STATE(39), 1,
      sym_number_type_decl,
    ACTIONS(78), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [245] = 6,
    ACTIONS(84), 1,
      anon_sym__,
    ACTIONS(88), 1,
      aux_sym__exponent_p_token1,
    ACTIONS(90), 1,
      aux_sym__dec_prefix_token1,
    STATE(14), 1,
      sym__exponent_p,
    STATE(37), 1,
      sym_number_type_decl,
    ACTIONS(86), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [283] = 6,
    ACTIONS(84), 1,
      anon_sym__,
    ACTIONS(88), 1,
      aux_sym__exponent_p_token1,
    ACTIONS(94), 1,
      aux_sym__dec_prefix_token1,
    STATE(8), 1,
      sym__exponent_p,
    STATE(38), 1,
      sym_number_type_decl,
    ACTIONS(92), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [321] = 4,
    ACTIONS(84), 1,
      anon_sym__,
    ACTIONS(98), 1,
      aux_sym__dec_prefix_token1,
    STATE(30), 1,
      sym_number_type_decl,
    ACTIONS(96), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [353] = 2,
    ACTIONS(102), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(100), 22,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      aux_sym__exponent_e_token1,
      anon_sym_DOT,
      anon_sym__,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [381] = 2,
    ACTIONS(106), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(104), 22,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      aux_sym__exponent_p_token1,
      anon_sym_DOT,
      anon_sym__,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [409] = 2,
    ACTIONS(110), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(108), 22,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      aux_sym__exponent_p_token1,
      anon_sym_DOT,
      anon_sym__,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [437] = 2,
    ACTIONS(114), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(112), 22,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      aux_sym__exponent_e_token1,
      anon_sym_DOT,
      anon_sym__,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [465] = 2,
    ACTIONS(118), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(116), 22,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      aux_sym__exponent_e_token1,
      anon_sym_DOT,
      anon_sym__,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [493] = 4,
    ACTIONS(84), 1,
      anon_sym__,
    ACTIONS(122), 1,
      aux_sym__dec_prefix_token1,
    STATE(29), 1,
      sym_number_type_decl,
    ACTIONS(120), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [525] = 2,
    ACTIONS(126), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(124), 22,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      aux_sym__exponent_p_token1,
      anon_sym_DOT,
      anon_sym__,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [553] = 2,
    ACTIONS(130), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(128), 22,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      aux_sym__exponent_p_token1,
      anon_sym_DOT,
      anon_sym__,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [581] = 4,
    ACTIONS(84), 1,
      anon_sym__,
    ACTIONS(134), 1,
      aux_sym__dec_prefix_token1,
    STATE(31), 1,
      sym_number_type_decl,
    ACTIONS(132), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [613] = 2,
    ACTIONS(138), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(136), 22,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      aux_sym__exponent_p_token1,
      anon_sym_DOT,
      anon_sym__,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [641] = 2,
    ACTIONS(142), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(140), 22,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      aux_sym__exponent_p_token1,
      anon_sym_DOT,
      anon_sym__,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [669] = 12,
    ACTIONS(9), 1,
      aux_sym__hex_number_token1,
    ACTIONS(11), 1,
      aux_sym__bin_number_token1,
    ACTIONS(13), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(15), 1,
      anon_sym_DOT,
    ACTIONS(17), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_SQUOTE,
    STATE(5), 1,
      sym__dec_prefix,
    STATE(34), 1,
      sym_expression,
    STATE(27), 2,
      sym_Number,
      sym_String,
    STATE(26), 3,
      sym_binary_expression,
      sym_unary_expression,
      sym_simple_expression,
    STATE(28), 3,
      sym__dec_number,
      sym__hex_number,
      sym__bin_number,
    ACTIONS(7), 6,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
  [716] = 2,
    ACTIONS(146), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(144), 21,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym__,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [743] = 2,
    ACTIONS(150), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(148), 21,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym__,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [770] = 12,
    ACTIONS(9), 1,
      aux_sym__hex_number_token1,
    ACTIONS(11), 1,
      aux_sym__bin_number_token1,
    ACTIONS(13), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(15), 1,
      anon_sym_DOT,
    ACTIONS(17), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_SQUOTE,
    STATE(5), 1,
      sym__dec_prefix,
    STATE(33), 1,
      sym_expression,
    STATE(27), 2,
      sym_Number,
      sym_String,
    STATE(26), 3,
      sym_binary_expression,
      sym_unary_expression,
      sym_simple_expression,
    STATE(28), 3,
      sym__dec_number,
      sym__hex_number,
      sym__bin_number,
    ACTIONS(7), 6,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
  [817] = 12,
    ACTIONS(9), 1,
      aux_sym__hex_number_token1,
    ACTIONS(11), 1,
      aux_sym__bin_number_token1,
    ACTIONS(13), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(15), 1,
      anon_sym_DOT,
    ACTIONS(17), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      anon_sym_SQUOTE,
    STATE(5), 1,
      sym__dec_prefix,
    STATE(36), 1,
      sym_expression,
    STATE(27), 2,
      sym_Number,
      sym_String,
    STATE(26), 3,
      sym_binary_expression,
      sym_unary_expression,
      sym_simple_expression,
    STATE(28), 3,
      sym__dec_number,
      sym__hex_number,
      sym__bin_number,
    ACTIONS(7), 6,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
  [864] = 4,
    ACTIONS(154), 1,
      anon_sym_or,
    ACTIONS(156), 1,
      anon_sym_and,
    ACTIONS(158), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(152), 18,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [894] = 2,
    ACTIONS(162), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(160), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [920] = 2,
    ACTIONS(166), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(164), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [946] = 2,
    ACTIONS(170), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(168), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [972] = 2,
    ACTIONS(174), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(172), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [998] = 2,
    ACTIONS(178), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(176), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1024] = 2,
    ACTIONS(182), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(180), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1050] = 2,
    ACTIONS(186), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(184), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1076] = 2,
    ACTIONS(190), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(188), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1102] = 3,
    ACTIONS(156), 1,
      anon_sym_and,
    ACTIONS(190), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(188), 19,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1130] = 2,
    ACTIONS(194), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(192), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1156] = 2,
    ACTIONS(198), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(196), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1182] = 2,
    ACTIONS(122), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(120), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1208] = 2,
    ACTIONS(98), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(96), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1234] = 2,
    ACTIONS(134), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(132), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1260] = 2,
    ACTIONS(202), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(200), 20,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_or,
      anon_sym_and,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1286] = 2,
    ACTIONS(158), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(152), 18,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1310] = 2,
    ACTIONS(206), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(204), 18,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1334] = 2,
    ACTIONS(210), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(208), 18,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1358] = 2,
    ACTIONS(214), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(212), 18,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1382] = 2,
    ACTIONS(218), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(216), 18,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1406] = 2,
    ACTIONS(222), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(220), 18,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1430] = 2,
    ACTIONS(226), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(224), 18,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1454] = 2,
    ACTIONS(230), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(228), 18,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1478] = 2,
    ACTIONS(234), 1,
      aux_sym__dec_prefix_token1,
    ACTIONS(232), 18,
      sym_short_comment_start,
      sym_long_comment_start,
      sym_string_block,
      sym_short_pp_start,
      sym_long_pp_start,
      ts_builtin_sym_end,
      anon_sym_COLON_COLON,
      anon_sym_not,
      anon_sym_DASH,
      anon_sym_POUND,
      anon_sym_TILDE,
      anon_sym_AMP,
      anon_sym_DOLLAR,
      aux_sym__hex_number_token1,
      aux_sym__bin_number_token1,
      anon_sym_DOT,
      anon_sym_DQUOTE,
      anon_sym_SQUOTE,
  [1502] = 3,
    ACTIONS(236), 1,
      anon_sym_DQUOTE,
    STATE(51), 1,
      aux_sym_String_repeat1,
    ACTIONS(238), 2,
      sym_unescaped_double_string_fragment,
      sym_escape_sequence,
  [1513] = 3,
    ACTIONS(240), 1,
      anon_sym_DQUOTE,
    STATE(55), 1,
      aux_sym_String_repeat1,
    ACTIONS(242), 2,
      sym_unescaped_double_string_fragment,
      sym_escape_sequence,
  [1524] = 3,
    ACTIONS(240), 1,
      anon_sym_SQUOTE,
    STATE(54), 1,
      aux_sym_String_repeat2,
    ACTIONS(244), 2,
      sym_unescaped_single_string_fragment,
      sym_escape_sequence,
  [1535] = 3,
    ACTIONS(236), 1,
      anon_sym_SQUOTE,
    STATE(52), 1,
      aux_sym_String_repeat2,
    ACTIONS(246), 2,
      sym_unescaped_single_string_fragment,
      sym_escape_sequence,
  [1546] = 3,
    ACTIONS(248), 1,
      anon_sym_SQUOTE,
    STATE(54), 1,
      aux_sym_String_repeat2,
    ACTIONS(250), 2,
      sym_unescaped_single_string_fragment,
      sym_escape_sequence,
  [1557] = 3,
    ACTIONS(253), 1,
      anon_sym_DQUOTE,
    STATE(55), 1,
      aux_sym_String_repeat1,
    ACTIONS(255), 2,
      sym_unescaped_double_string_fragment,
      sym_escape_sequence,
  [1568] = 3,
    ACTIONS(258), 1,
      anon_sym_DOT,
    ACTIONS(260), 1,
      aux_sym__hex_prefix_token1,
    STATE(7), 1,
      sym__hex_prefix,
  [1578] = 3,
    ACTIONS(262), 1,
      anon_sym_DOT,
    ACTIONS(264), 1,
      aux_sym__bin_prefix_token1,
    STATE(6), 1,
      sym__bin_prefix,
  [1588] = 2,
    ACTIONS(266), 1,
      sym__name_prefix,
    STATE(64), 1,
      sym_Name,
  [1595] = 2,
    ACTIONS(268), 1,
      aux_sym_short_pp_body_token1,
    STATE(47), 1,
      sym_short_pp_body,
  [1602] = 2,
    ACTIONS(270), 1,
      aux_sym_short_pp_body_token1,
    STATE(44), 1,
      sym_short_comment_body,
  [1609] = 1,
    ACTIONS(272), 1,
      aux_sym__hex_prefix_token1,
  [1613] = 1,
    ACTIONS(274), 1,
      aux_sym__dec_prefix_token1,
  [1617] = 1,
    ACTIONS(276), 1,
      anon_sym_COLON_COLON,
  [1621] = 1,
    ACTIONS(278), 1,
      anon_sym_COLON_COLON,
  [1625] = 1,
    ACTIONS(280), 1,
      sym__name_suffix,
  [1629] = 1,
    ACTIONS(282), 1,
      sym_long_pp_end,
  [1633] = 1,
    ACTIONS(284), 1,
      sym_long_pp_body,
  [1637] = 1,
    ACTIONS(286), 1,
      aux_sym__bin_prefix_token1,
  [1641] = 1,
    ACTIONS(288), 1,
      sym_long_comment_body,
  [1645] = 1,
    ACTIONS(290), 1,
      sym_long_comment_end,
  [1649] = 1,
    ACTIONS(292), 1,
      sym__exp_digits,
  [1653] = 1,
    ACTIONS(294), 1,
      sym__exp_digits,
  [1657] = 1,
    ACTIONS(296), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 43,
  [SMALL_STATE(4)] = 125,
  [SMALL_STATE(5)] = 207,
  [SMALL_STATE(6)] = 245,
  [SMALL_STATE(7)] = 283,
  [SMALL_STATE(8)] = 321,
  [SMALL_STATE(9)] = 353,
  [SMALL_STATE(10)] = 381,
  [SMALL_STATE(11)] = 409,
  [SMALL_STATE(12)] = 437,
  [SMALL_STATE(13)] = 465,
  [SMALL_STATE(14)] = 493,
  [SMALL_STATE(15)] = 525,
  [SMALL_STATE(16)] = 553,
  [SMALL_STATE(17)] = 581,
  [SMALL_STATE(18)] = 613,
  [SMALL_STATE(19)] = 641,
  [SMALL_STATE(20)] = 669,
  [SMALL_STATE(21)] = 716,
  [SMALL_STATE(22)] = 743,
  [SMALL_STATE(23)] = 770,
  [SMALL_STATE(24)] = 817,
  [SMALL_STATE(25)] = 864,
  [SMALL_STATE(26)] = 894,
  [SMALL_STATE(27)] = 920,
  [SMALL_STATE(28)] = 946,
  [SMALL_STATE(29)] = 972,
  [SMALL_STATE(30)] = 998,
  [SMALL_STATE(31)] = 1024,
  [SMALL_STATE(32)] = 1050,
  [SMALL_STATE(33)] = 1076,
  [SMALL_STATE(34)] = 1102,
  [SMALL_STATE(35)] = 1130,
  [SMALL_STATE(36)] = 1156,
  [SMALL_STATE(37)] = 1182,
  [SMALL_STATE(38)] = 1208,
  [SMALL_STATE(39)] = 1234,
  [SMALL_STATE(40)] = 1260,
  [SMALL_STATE(41)] = 1286,
  [SMALL_STATE(42)] = 1310,
  [SMALL_STATE(43)] = 1334,
  [SMALL_STATE(44)] = 1358,
  [SMALL_STATE(45)] = 1382,
  [SMALL_STATE(46)] = 1406,
  [SMALL_STATE(47)] = 1430,
  [SMALL_STATE(48)] = 1454,
  [SMALL_STATE(49)] = 1478,
  [SMALL_STATE(50)] = 1502,
  [SMALL_STATE(51)] = 1513,
  [SMALL_STATE(52)] = 1524,
  [SMALL_STATE(53)] = 1535,
  [SMALL_STATE(54)] = 1546,
  [SMALL_STATE(55)] = 1557,
  [SMALL_STATE(56)] = 1568,
  [SMALL_STATE(57)] = 1578,
  [SMALL_STATE(58)] = 1588,
  [SMALL_STATE(59)] = 1595,
  [SMALL_STATE(60)] = 1602,
  [SMALL_STATE(61)] = 1609,
  [SMALL_STATE(62)] = 1613,
  [SMALL_STATE(63)] = 1617,
  [SMALL_STATE(64)] = 1621,
  [SMALL_STATE(65)] = 1625,
  [SMALL_STATE(66)] = 1629,
  [SMALL_STATE(67)] = 1633,
  [SMALL_STATE(68)] = 1637,
  [SMALL_STATE(69)] = 1641,
  [SMALL_STATE(70)] = 1645,
  [SMALL_STATE(71)] = 1649,
  [SMALL_STATE(72)] = 1653,
  [SMALL_STATE(73)] = 1657,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(58),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(24),
  [43] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(13),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [64] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(69),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(67),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dec_number, 1, 0, 0),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dec_number, 1, 0, 0),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bin_number, 2, 0, 0),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bin_number, 2, 0, 0),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__hex_number, 2, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__hex_number, 2, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__hex_number, 3, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__hex_number, 3, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dec_prefix, 2, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dec_prefix, 2, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bin_prefix, 3, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bin_prefix, 3, 0, 0),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__hex_prefix, 3, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__hex_prefix, 3, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dec_prefix, 3, 0, 0),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dec_prefix, 3, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dec_prefix, 1, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dec_prefix, 1, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bin_number, 3, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bin_number, 3, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bin_prefix, 2, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bin_prefix, 2, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__hex_prefix, 2, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__hex_prefix, 2, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dec_number, 2, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dec_number, 2, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__hex_prefix, 1, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__hex_prefix, 1, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bin_prefix, 1, 0, 0),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bin_prefix, 1, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exponent_p, 2, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__exponent_p, 2, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__exponent_e, 2, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__exponent_e, 2, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Block, 1, 0, 0),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Block, 1, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 1, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_simple_expression, 1, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_simple_expression, 1, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Number, 1, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Number, 1, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bin_number, 4, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bin_number, 4, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__hex_number, 4, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__hex_number, 4, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__dec_number, 3, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__dec_number, 3, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_number_type_decl, 2, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_number_type_decl, 2, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, 0, 2),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3, 0, 2),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_String, 3, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_String, 3, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2, 0, 1),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2, 0, 1),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_String, 2, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_String, 2, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_long_pp, 3, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_long_pp, 3, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_comment_body, 1, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_short_comment_body, 1, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_comment, 2, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_short_comment, 2, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_long_comment, 3, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_long_comment, 3, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_pp_body, 1, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_short_pp_body, 1, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_short_pp, 2, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_short_pp, 2, 0, 0),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 1, 0, 0),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Label, 3, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_Label, 3, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [240] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_String_repeat2, 2, 0, 0),
  [250] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_String_repeat2, 2, 0, 0), SHIFT_REPEAT(54),
  [253] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_String_repeat1, 2, 0, 0),
  [255] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_String_repeat1, 2, 0, 0), SHIFT_REPEAT(55),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [276] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_Name, 2, 0, 0),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [286] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [296] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_short_comment_start = 0,
  ts_external_token_long_comment_start = 1,
  ts_external_token_long_comment_body = 2,
  ts_external_token_long_comment_end = 3,
  ts_external_token_string_block = 4,
  ts_external_token_short_pp_start = 5,
  ts_external_token_long_pp_start = 6,
  ts_external_token_long_pp_body = 7,
  ts_external_token_long_pp_end = 8,
  ts_external_token_ERROR_SENTINEL = 9,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_short_comment_start] = sym_short_comment_start,
  [ts_external_token_long_comment_start] = sym_long_comment_start,
  [ts_external_token_long_comment_body] = sym_long_comment_body,
  [ts_external_token_long_comment_end] = sym_long_comment_end,
  [ts_external_token_string_block] = sym_string_block,
  [ts_external_token_short_pp_start] = sym_short_pp_start,
  [ts_external_token_long_pp_start] = sym_long_pp_start,
  [ts_external_token_long_pp_body] = sym_long_pp_body,
  [ts_external_token_long_pp_end] = sym_long_pp_end,
  [ts_external_token_ERROR_SENTINEL] = sym_ERROR_SENTINEL,
};

static const bool ts_external_scanner_states[7][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_short_comment_start] = true,
    [ts_external_token_long_comment_start] = true,
    [ts_external_token_long_comment_body] = true,
    [ts_external_token_long_comment_end] = true,
    [ts_external_token_string_block] = true,
    [ts_external_token_short_pp_start] = true,
    [ts_external_token_long_pp_start] = true,
    [ts_external_token_long_pp_body] = true,
    [ts_external_token_long_pp_end] = true,
    [ts_external_token_ERROR_SENTINEL] = true,
  },
  [2] = {
    [ts_external_token_short_comment_start] = true,
    [ts_external_token_long_comment_start] = true,
    [ts_external_token_string_block] = true,
    [ts_external_token_short_pp_start] = true,
    [ts_external_token_long_pp_start] = true,
  },
  [3] = {
    [ts_external_token_long_pp_end] = true,
  },
  [4] = {
    [ts_external_token_long_pp_body] = true,
  },
  [5] = {
    [ts_external_token_long_comment_body] = true,
  },
  [6] = {
    [ts_external_token_long_comment_end] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_neluablk_external_scanner_create(void);
void tree_sitter_neluablk_external_scanner_destroy(void *);
bool tree_sitter_neluablk_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_neluablk_external_scanner_serialize(void *, char *);
void tree_sitter_neluablk_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_neluablk(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_neluablk_external_scanner_create,
      tree_sitter_neluablk_external_scanner_destroy,
      tree_sitter_neluablk_external_scanner_scan,
      tree_sitter_neluablk_external_scanner_serialize,
      tree_sitter_neluablk_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
