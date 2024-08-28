/*
[ ] How does precendence work?
  [x] What does precedence look like when we do a nelua --print-ast
    In tree-sitter terms, a or b and c = BinaryOp "or" a (BinaryOp "and" b c)
                          a and b or c = BinaryOp (BinaryOp "and" a b) "or" c
  [ ] Reproduce output for and/or example
*/
const name = 'neluablk'

// taken from tree-sitter-c
const PREC = {
  PAREN_DECLARATOR: -10,
  ASSIGNMENT: -2,
  CONDITIONAL: -1,
  DEFAULT: 0,
  LOGICAL_OR: 1,
  LOGICAL_AND: 2,
  INCLUSIVE_OR: 3,
  EXCLUSIVE_OR: 4,
  BITWISE_AND: 5,
  EQUAL: 6,
  RELATIONAL: 7,
  OFFSETOF: 8,
  SHIFT: 9,
  ADD: 10,
  MULTIPLY: 11,
  CAST: 12,
  SIZEOF: 13,
  UNARY: 14,
  CALL: 15,
  FIELD: 16,
  SUBSCRIPT: 17,
}

const numberTypeEndings = [
  'i', 'integer',
  'u', 'uinteger',
  'n', 'number',
  'b', 'byte',
  'is', 'isize',
  'i8', 'int8',
  'i16', 'int16',
  'i32', 'int32',
  'i64', 'int64',
  'i128', 'int128',
  'us', 'usize',
  'u8', 'uint8',
  'u16', 'uint16',
  'u32', 'uint32',
  'u64', 'uint64',
  'u128', 'uint128',
  'f32', 'float32',
  'f64', 'float64',
  'f128','float128',
]


// @ts-ignore
function listOf(rule, sep = ',') {
  return seq(rule, repeat(seq(sep, rule)))
}

const externals = $ => {
  return [
    $.short_comment_start,
    $.long_comment_start,
    $.long_comment_body,
    $.long_comment_end,
    $.string_block,
    $.short_pp_start,
    $.long_pp_start,
    $.long_pp_body,
    $.long_pp_end,
    // $.string_content,
    // $.string_block_end,
    // error sentinel should never be included in the rules, 
    // it's just here to prevent extra scanning during error recover
    $.ERROR_SENTINEL
    // $.long_comment_start,
    // $.long_comment_content,
    // $.long_comment_end,
  ]
}

const anythingButLinebreakRe = /(\\+(.|\r?\n)|[^\\\n])*/
const extras = $ => { 
  return [/\s/] 
}

const rules = {
  source_file: $ => {
    return repeat($.Block)
  },
  Block: $ => {
    return choice(
      $.Label, // remove? 
      $.expression, // remove? 
      $.comment, $.string_block, $.short_pp, $.long_pp)
  },
  _statement: $ => {
    return choice($.Label)
  },
  // -- Statements
  Label: $ => {
    return seq('::', $.Name, '::')
  },
  Return: $ => {
    return seq(`return`, listOf($.expression))
  },
  // --------------

  // Expressions
  // We're gonna build these different than PEG, instead closer to how 
  // most tree-sitter implementations handle binary/unary expressions
  expression: $ => {
    return choice(
      $.binary_expression,
      $.unary_expression,
      // PEG: exprsimple
      $.simple_expression,
      // just used for testing
      // $._temporary_expression
      // $.simple_expression,
      // $.primary_expression
    )
  },

  // used for testing things that may be difficult to get to
  _temporary_expression: $ => {
    return $.field
  },

  binary_expression: $ => {
    const ops = [
        // opor
        ['or', PREC.LOGICAL_OR],
        // opand
        ['and', PREC.LOGICAL_AND],
      ]
    const choices = ops
      .map(([operator, precedence]) => {
        return prec.left(precedence,
          seq(
            field('left', $.expression), 
            field('operator', operator),
            field('right', $.expression),
          )
        )
      })
    return choice(...choices)
  },

  unary_expression: $ => {
    return prec.left(PREC.UNARY, seq(
        field('operator', choice('not', '-', '#', '~', '&', '$')),
        field('argument', $.expression),
      )
    )
  },

  simple_expression: $ => {
    // TODO Add each simple expression
    return choice($.Number, $.String, $.Boolean, $.Nilptr, $.Nil, $.Varargs, $.InitList, $.Function)
  },

   
  // -----------
  // <<-- START SIMPLE EXPRESSIONS -->>
  //exprsimple      <-- Number / String / Type / InitList / Boolean /
  //                  Function / Nilptr / Nil / Varargs / exprsuffixed
  // [x] Do we parse type declarations? Yes
  Number: $ => {
    return choice($._hex_number, $._bin_number, $._dec_number)  
  },
  _dec_number: $ => {
    return seq(
      alias($._dec_prefix, $.dec_number),
      optional($._exponent_e),
      optional($.number_type_decl),
    )
  },
  _hex_number: $ => {
    return seq(
      /0[xX]/,
      alias($._hex_prefix, $.hex_number),
      optional($._exponent_p),
      optional($.number_type_decl),
    )
  },
  _bin_number: $ => {
    return seq(
      /0[bB]/,
      alias($._bin_prefix, $.bin_number),
      optional($._exponent_p),
      optional($.number_type_decl),
    )
  },
  _exponent_e: $ => {
    return seq(/[eE]/, alias($._exp_digits, $.exponent))
  },
  _exponent_p: $ => {
    return seq(/[pP]/, alias($._exp_digits, $.exponent))
  },
  _dec_prefix: $ => {
    return choice(
      prec.left(2, seq(/[0-9]+/, optional(seq(".", /[0-9]*/)))),
      prec.left(1, seq(".", /[0-9]+/)),
    )
  },
  _hex_prefix: $ => {
    return choice(
      prec.left(2, seq(/[0-9a-fA-F]+/, optional(seq(".", /[0-9a-fA-F]*/)))),
      prec.left(1, seq(".", /[0-9a-fA-F]+/)),
    )
  },
  _bin_prefix: $ => {
    return choice(
      prec.left(2, seq(/[01]+/, optional(seq(".", /[01]*/)))),
      prec.left(1, seq(".", /[01]+/)),
    )
  },
  _exp_digits: $ => /[+-]?[0-9]+/,
  number_type_decl: $ => {
    return seq('_', choice(...numberTypeEndings))
  },

  String: $ => {
    const doubleQuote = seq(
      '"',
      repeat(
        choice(
          alias($.unescaped_double_string_fragment, $.string_fragment),
          $.escape_sequence,
        )
      ),
      '"',
    ) 
    const singleQuote = seq(
      '\'', 
      repeat(
        choice(
          alias($.unescaped_single_string_fragment, $.string_fragment),
          $.escape_sequence,
        )
      ),
      '\'',
    )
    return choice(
      doubleQuote,
      singleQuote
    )
  },
  unescaped_single_string_fragment: $ => {
    return token.immediate(prec(1, /[^'\\\r\n]+/))
  },
  unescaped_double_string_fragment: $ => {
    return token.immediate(prec(1, /[^"\\\r\n]+/))
  },
  /*
  ESCAPE          <-- [\'"] 
                    ('n' $10 / 't' $9 / 'r' $13 / 'a' $7 / 'b' $8 / 'v' $11 / 'f' $12)->tochar /
                    ('x' {HEX_DIGIT^2} $16)->tochar /
                    ('u' '{' {HEX_DIGIT^+1} '}' $16)->toutf8char /
                    ('z' SPACE*)->'' /
                    (DEC_DIGIT DEC_DIGIT^-1 !DEC_DIGIT / [012] DEC_DIGIT^2)->tochar /
                    (LINEBREAK $10)->tochar
  */
  escape_sequence: _ => {
    const seqs = [

- [ ] Add Pair
      /[trabvf\\]/,
      /x[0-9a-fA-F]{2}/,
      // e.g. u{09AF}
      /u\{[0-9a-fA-F]+\}/,
      seq('z', repeat(/\s|\n|\r\n/)), 
      /\d{1,2}/,
      // /\b\d{1,2}\b/,
      /[012]{3}/,
       // CRLF
      /\r\n|\n\r|\n|\r/,
    ]
    return token.immediate(seq('\\', choice(...seqs)))
  },

  Boolean: $ => {
    return choice('true', 'false')
  },
  Nilptr: _ => 'nilptr',
  Nil: _ => 'nil',
  Varargs: _ => '...',
  Id: $ => {
    return $.Name
  },
  // PEG: idsuffixed
  IdSuffixed: $ => {
    return seq($.Id, repeat1(seq('.', $.Name)))
  },
  // funcname        <-- (id DotIndex* ColonIndex?)~>rfoldright
  FuncName: $ => {
    return seq($.Id, repeat($.DotIndex), optional($.ColonIndex))
  },
  // DotIndex        <== `.` @name
  DotIndex: $ => {
    return seq('.', $.Name)
  },
  // ColonIndex      <== `:` @name
  ColonIndex: $ => {
    return seq(':', $.Name)
  },
  IdDecl: $ => {
    return seq($.Id, optional($.typeexpr))
  },
  IdDecls: $ => {
    return listOf($.IdDecl, ',')
  },
  InitList: $ => {
    return seq(
      '{',
      optional(listOf($.field, $.fieldsep)),
      '}',
    )
  },
  field: $ => {
    return choice(
          $.Pair,
          $.expression
        )
  },
  // Pair            <== `[` @expr @`]` @`=` @expr / name `=` @expr / `=` @id -> pair_sugar
  Pair: $ => {
    return choice(
      seq('[', $.expression, ']', '=', $.expression),
      seq('name', '=', $.expression),
      // TODO: I don't know what pair_sugar is supposed to do. I didn't see anything in the tests that wouldn't be captured by the first two choices.
    )
  },
  fieldsep: _ => {
    return choice(',', ';')
  },
  Function: $ => {
    return seq('function', $.FunctionBody)
  },
  // TODO: Make this work, gonna probably need initlist first
  FunctionBody: $ => {
    return 'funcbody'
  },

   // <<-- END SIMPLE EXPRESSIONS -->>

   // <<-- TYPE EXPRESSIONS -->>
   typeexpr: $ => {
     return seq(
       $.typeexprunary, 
       optional($.typevaris),
     )
   },
   // [ ] typexprsimple   <-- RecordType / UnionType / EnumType / FuncType / ArrayType / PointerType /
   //                     VariantType / (typeexprprim typeopgen?)~>foldleft
   typeexprsimple: $ => {
     return choice(
       $.RecordType,
       $.UnionType,
       // $.EnumType,
       // $.FuncType,
       // $.ArrayType,
       // $.PointerType,
       // $.VariantType, 
       // seq($.typeexprprim, optional($typeopgen))
     )
   },

   // typeexprunary   <-- (typeopunary* typexprsimple)->rfoldleft
   typeexprunary: $ => {
     return seq(repeat($.typeopunary), $.typeexprsimple)
   },

   // [x] typevaris : VariantType   <== `|` @typeexpruary (`|` @typeexprunary)*
   typevaris: $ => {
     return repeat1(seq('|', $.typeexprunary)) 
   },

   // [x] typeexprprim    <-- idsuffixed / id
   typeexprprim: $ => {
     return choice($.Id, $.IdSuffixed)
   },
   // [x] annots          <-| `<` @Annotation (`,` @Annotation)* @`>`
   annots: $ => {
     return seq('<', listOf($.Annotation), '>')
   },
   // name annotargs?
   Annotation: $ => {
     return seq($.Name, optional($.annotargs))
   },
   // annotargs       <-| `(` (expr (`,` @expr)*)? @`)` / InitList / String / PreprocessExpr
   annotargs: $ => {
     return choice(
       seq('(', optional(listOf($.expression)), ')'),
       $.InitList,
       $.String,
       $.pp_expr,
     )
   },
   // typeopunary     <-- typeopptr / typeopopt / typeoparr
   typeopunary: $ => {
     return choice($.typeopptr, $.typeopopt, $.typeoparr)
   },
   typeopptr: _ => '*',
   typeopopt: _ => '?',
   typeoparr: $ => {
     return seq('[', optional($.expression), ']')
   },
   // <<-- END TYPE EXPRESSIONS -->>

   // <<-- TYPES -->
   // -- Types
   // [x] RecordType      <== 'record' WORDSKIP @`{` (RecordField (fieldsep RecordField)* fieldsep?)? @`}`
   RecordType: $ => {
     return seq(
       'record', 
       '{', 
       repeat(
         seq(
           listOf($.RecordField, $.fieldsep),
           optional($.fieldsep)
         )
       ),
       '}'
     )
   },
   RecordField: $ => {
     return seq($.Name, ':', $.typeexpr)
   },
   // [x] UnionType       <== 'union' WORDSKIP @`{` (UnionField (fieldsep UnionField)* fieldsep?)? @`}`
   UnionType: $ => {
     return seq(
       'union',
       '{',
       repeat(
         seq(
           listOf($.UnionField, $.fieldsep),
           optional($.fieldsep)
         )
       ),
       '}'
     ) 
   },
   // [x] UnionField      <== name `:` @typeexpr / $false typeexpr
   UnionField: $ => {
     return choice(seq($.Name, ':', $.typeexpr), $.typeexpr)
   },
   // [x] EnumType        <== 'enum' WORDSKIP (`(` @typeexpr @`)`)~? @`{` @enumfields @`}`
   // enumfields      <-| EnumField (fieldsep EnumField)* fieldsep?
   EnumType: $ => {
     return seq(
       'enum',
       optional(seq('(', $.typeexpr, ')')),
       '{',
       seq(
         listOf($.EnumField, $.fieldsep), 
         optional($.fieldsep)
       ),
       '}'
     )
   },
   // [x] EnumField       <== name (`=` @expr)?
   EnumField: $ => {
     return seq($.name, optional(seq('=', $.expression)))
   },
   // FuncType        <== 'function' WORDSKIP @`(` functypeargs @`)`(`:` @funcrets)?
   FuncType: $ => {
     return seq(
       'function',
       '(',
    )
   },
   // functypeargs    <-| (functypearg (`,` functypearg)* (`,` VarargsType)? / VarargsType)?
   functypeargs: $ => {},
   functypearg: $ => {
     return choice($.typeddecl, $.typeexpr)
   },
   // typeddecl    : IdDecl <== name `:` @typeexpr annots?
   typeddecl: $ => {
     return seq($.Name, ':', $.typeexpr, optional($.annots))
   },
   // funcrets        <-| `(` typeexpr (`,` @typeexpr)* @`)` / typeexpr
   funcrets: $ => {},
   // [ ] ArrayType       <== 'array' WORDSKIP @`(` @typeexpr (`,` @expr)? @`)`
   // ArrayType: $ => {},
   // [ ] PointerType     <== 'pointer' WORDSKIP (`(` @typeexpr @`)`)?
   // PointerType: $ => {},
   // [ ] VariantType     <== 'variant' WORDSKIP `(` @typearg (`,` @typearg)* @`)`
   // VariantType: $ => {},
   // [ ] VarargsType     <== `...` (`:` @name)?
   // <<-- END TYPES -->



  comment: $ => {
    return choice($.long_comment, $.short_comment)
  },
  
  // ## for i = 1,4 do
  short_pp: $ => {
    return seq($.short_pp_start, $.short_pp_body)
  },
  short_pp_body: $ => {
    return anythingButLinebreakRe
  },
  // ##[=[ local foo = [[mystring]] ]=]
  long_pp: $ => {
    return seq($.long_pp_start, $.long_pp_body, $.long_pp_end)
  },
  // -- my short comment
  short_comment: $ => {
    return seq($.short_comment_start, $.short_comment_body)
  },
  short_comment_body: $ => {
    return anythingButLinebreakRe
  },
  // --[=[ long multiline comment ]=]
  long_comment: $ => {
    return seq($.long_comment_start, $.long_comment_body, $.long_comment_end)
  },
  hello: $ => {
    return choice('hello', 'bonjour')
  },
  _name_prefix: $ => {
    return /[A-Za-z\xC2-\xFD\x80-\xBF]/
  },
  _name_suffix: $ => {
    return /[\dA-Za-z\xC2-\xFD\x80-\xBF]*/
  },
  Name: $ => {
    return seq($._name_prefix, $._name_suffix)
  },
  // PreprocessExpr `#[` {@expr->0} @`]#`
  // I'm pretty sure the body is Lua, not Nelua, so we'll just capture anything and inject highlighting
  pp_expr: $ => {
    return seq('#[', field('body', anythingButLinebreakRe), '#]')
  },
  // PreprocessName
  pp_name: $ => {
    return seq('#|', field('body', anythingButLinebreakRe), '#|')
  },
  // string_block: $ => {
  //   return seq($.string_block_start, repeat($.string_content), $.string_block_end)
  // },
  // string_block_content: $ => {
  //   return 
  // },
  // _newline: $ => {
  //   return choice('\n', '\r', '\n\r', '\r\n')
  // }
  // comment: $ => {
    
  // },
  // comment2: $ => {
  //   return '--comment'
  // },
  // comment: $ => {
  //   return choice($.short_comment, seq($.long_comment_start, $.long_comment_end))
  // },
}

const G = {
  name,
  externals,
  rules,
  extras
}

module.exports = grammar(G)
