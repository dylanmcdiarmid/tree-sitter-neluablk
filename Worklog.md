### 9-9-2024

**Type Expressions**
- [x] Simple expressions: Id and IdDecl
  - [x] typeexpr
    - [x] typeexprunary
      - [ ] 0 prefix
        - this is typeexprsimple
        - [x] typeexprprim
          - [x] Id
          - [x] IdSuffixed
        - [x] RecordType
        - [x] UnionType
        - [x] EnumType
        - [x] EnumType with values
        - [x] FuncType
          - [x] simple: function()
          - [x] with ret
          - [x] with args and ret
        - [x] ArrayType
        - [x] PointerType
          - [x] simple
          - [x] specific
          - [x] * alias
            - (this parses but we may need to adjust the AST)
        - [x] VariantType
          - [x] keyword variant
          - [x] pipe separated
        - [x] GenericType
          - This is represented by the typeopgen rule, and did not work on first try
          - I think it's the same problem we had with callargs involving parens. I was able to save it the same way, giving `$.generic` a high precedence and creating a conflict for the choice
          - [x] Fix GenericType
      - [x] 1 prefix
      - [x] 2 prefix
    - [x] typevaris
    - [x] typeexprprim
  - [x] annots

I've been thinking about how I'd like to proceed now that I've almost completely the complete PEG -> tree-sitter port. Now that I've had the experience of doing the port, in retrospect I would have preferred to have a list of specimens that I have classified into expected scopes (scopes in the context of syntax highlighting https://tree-sitter.github.io/tree-sitter/syntax-highlighting ).

Originally I had Phase 3 setup to be the cleanup/syntax highlighting phase. Instead I'm going to do a Phase 3 that is purely preparing and documenting specimens so that when I do the cleanup I have something I can use as a guide.

It should just be FuncDef to go and I'll be ready for the next phase, I will try and finish that up tomorrow.

**FuncDef**
- [x] Simple case: `local function f() end`
- [ ] funcargs
  - [ ] iddecl
    - [ ] pp_expr
    - [x] id
    - [x] id (list)
    - [ ] id: typeexpr
  - [ ] VarargsType
- [ ] funcrets
- [ ] annots
- [ ] body Block


### 9-5-2024
- [x] callargs is trouble. `a(1)` is NOT working, `a.b(1)` IS working, `a.b(1)(2)` is NOT working
  - This rule isn't really particularly strange, so I'm going to see how it's implemented in javascript/c
  - I'm not sure how much help I'm getting here, it seems to be some interference between Paren being a valid expression, but I don't quite get where things are going wrong. Calls like `b.c'a''b'` work, as does b.c(a)'b', but b.c(a)(b) does not work, and instead it looks like we attempt to parse an expression. 
  - tree-sitter is sending me off the deep end today. In callargs, it seems it's particularly the `seq` that breaks it. For example, I can use `seq('(', ')')` and it will fail, but if I match against `'()'` it will work using example `b.c()()`
  - Ultimately adding a "conflicts" entry between indexsuffix and its variations worked, but I'm not entirely sure why. My understanding is that it forces a resolution at runtime. I think this is something I'll address once I move on to the cleanup phase.

Moving on to finish the spot checks today... 
**Spot Checks**
- [x] preprocessor call (ppcallprim) - I think this is like foo!('bar') but I'm not super familiar with the language. nelua --print-ast does recognize it
- [x] do expression
- [x] parens

These last expression spot checks cover everything an Assign can do. Next I'd like to handle function declaration, which I think will also lead to full coverage of type declarations (although of course we can also test that through Assign to Type, which is `a = @mytype` syntax.

**FuncDef**
- [x] Simple case: `local function f() end`

### 9-4-2024
I was able to solve the issue with variation precedence fairly easily using essentially the method I proposed at the end of yesterday's work session. "Eliminate optional, replace with choice" is the gist of the pattern, and it may be applicable in other places.

It did make me think about how messy the direct translation from the PEG is, and really it's partially because I've been ignoring tokens that aren't real in the PEG. I don't quite know what to do about it yet, but after I think after I finish the rest of the smoke tests, I may move on to the next phase this week.

I believe I also will have a few more rules to port, but I think I'm starting to close in on full coverage.

During testing I was wondering why the operator field wasn't showing up. Apparently https://github.com/tree-sitter/tree-sitter/issues/767 is a thing, and specifically mentions tree-sitter-c. This is fairly surprising behavior, and I'd like to use a different pattern, honestly. I asked about it in the tree-sitter discord today, as now I'm not sure I should be using parse for spot checking if it's going to hide things the queries can see.

- [x] Rewrite binary expressions to use a different pattern that allows for the operator field to show up during a parse.
- [x] Fix Call rule, it's currently erroring
  - Fixed the trivial case by removing the unnecessary Call rule, then using a right associativity instead of left on exprsuffixed. This doesn't appear to be working on a repeat case though, e.g. `a.b.c()` is failing
  - [x] Create a indexsuffix rule that has a guaranteed call as part of its rule
    - `a.b.c()` failing: My current strategy for fixing this is to think about what types of pattern seem to work well. Getting rid of optional worked, so I'm going to try and make the `choice` here a bit clearer and see if that helps the parser decide correctly. My theory right now is that it's still trying to parse the Name once it hits the parens, instead of seeing it as a choice between an id vs a call.
    - This strategy worked, resulting in a choice between indexsuffix and indexsuffix_callargs. It will probably will crop up again, as the PEG seems to encourage this pattern when translating directly. 


**Spot Checks**
- [x] type variations
- [x] Binary Expressions
  - [x] or
  - [x] and
  - [x] == (cmp)
  - [x] ~=
  - [x] <=
  - [x] <
  - [x] >=
  - [x] >
  - [x] |
  - [x] ~
  - [x] &
  - [x] <<
  - [x] >>>
  - [x] >>
  - [x] ..
  - [x] + 
  - [x] - 
  - [x] * 
  - [x] /// 
  - [x] // 
  - [x] / 
  - [x] %%% 
  - [x] % 
- [x] Unary expressions
  - [x] not
  - [x] -
  - [x] #
  - [x] ~
  - [x] &
  - [x] $
- [x] Combo binary and unary, e.g. `1 - -1`
- [x] InitList
  - [x] empty
  - [x] single
  - [x] multiple
- [x] true
- [x] false
- [x] nilptr
- [x] nil
- [x] ... (varargs)
- [ ] suffixed expressions
  - [x] id
    - [x] simple
    - [x] single index suffix
    - [x] single call suffix
    - [x] single index suffix, single call suffix
    - [x] index suffix, key suffix, call suffix
    - [x] call suffix with str
    - [x] call suffix with parens containing expression
    - [x] call suffix with init list
  - [ ] preprocessor call (ppcallprim)
  - [ ] do expression
  - [ ] parens

### 9-3-2024
Trying to find my place after a long weekend without coding. Looks like we're filling in the `expression` rule (`expr` in the PEG). I'll be running generate more often during this worksession, as I ran into a lot of precedence resolution I didn't really understand last time.

I've got the simple assign expression parsing without error, but right now it's reading a Type where it shouldn't.

- [x] Fix `a = b` reading a Type
  - This resulted from a bad translation of Type from the PEG, I missed that it was a sequence.

**Spot Checks**
- [x] number assignment
- [x] double quote string assignment
- [x] single quote string assignment
- [x] string block assignment
- [x] type assignment
- [x] unary type assignment
  - [x] pointer
  - [x] optional
  - [x] array
- [ ] type variations
  - Right now it looks like bitwise or is taking precedence over type variation signifier.
  
The type variant case, simplified to a = @a | b, should help me understand precedence if I can untangle it. Nelua correctly parses it as assignment to a Variant Type, whereas we get a binary expression from tree-sitter.

I added high precedence rules all the way down the chain, but I'm finding that I can only get them to kick in if I remove "optional" from typevaris. Komo's implementation errors in this case so I can't use that either.

This may be a case where we just need to rebuild the type variations section with an eye towards LR parsing. Unfortunately, minimal case reproduction can be very difficult with type sitter, which can make posing a question like this to the tree-sitter discord annoying enough that I don't want to do it.

Next working session: Try taking advantage of the discovery that removing "optional" from typevaris in the type expression makes the precedence work correctly. We can try a choice token perhaps, typeexprvaris vs typeexpr, rather than a single token with optional.


### 8-30-2024
Continue work on getting the Assign rule fully ported.

After finishing up filling in the missing symbols, I ran into an conflict problem with PointerType. I looked at Komo's version, but his doesn't support the ( typeexpr ) sequence being optional, which is how I'm reading the PEG.

```
Unresolved conflict for symbol sequence:

  'function'  '('  funcargs  ')'  ':'  'pointer'  •  '('  …

Possible interpretations:

  1:  'function'  '('  funcargs  ')'  ':'  (PointerType  'pointer'  •  '('  typeexpr  ')')
  2:  'function'  '('  funcargs  ')'  ':'  (PointerType  'pointer')  •  '('  …
```

For now I'll fill in prec.left with a FIXME once I understand a bit better exactly what cases trigger this conflict.

I hit a ton of cases of weird precedence, and I think we'll just need to wait until I create test cases for all the different type expressions to make sure they are resolving correctly. Hitting like 10 precedence problems in a row makes me question the wisdom of filling in lots of rules at once, but this may be a case where the grass will always be greener.

Hypothetically, we should be able to start running down Assign rule cases now, so that's up next.

In practice we're still missing a bunch of rules. `var` was actually unfinished so filling in more here, but making sure to actually run the code more often to avoid a long chain of errors.

We've filled in a bunch more rules, but Assign is still failing to parse `a = b` properly. Now we need to walk through why this might be.

`nelua --print-ast example_assign.neluablk` gives us the equivalent of `Assign((Id "a"), (Id "b"))`
Obviously the PEG gives way fewer nodes than our wip version of tree-sitter does, but lets figure out what is failing to capture

For next work session, we need to finish filling out the "expression" rule (expr in the PEG). That's where Assign is currently breaking.
 

### 8-29-2024
Plan for today is to try and get Assign statements actually running after setting them up yesterday.

- [x] add funcbody
- [x] add funcargs
- [x] add suffixeddecls

There is a long dive of stuff to continue to fill in before we can call assign. I've also noticed today that I was a bit haphazard at the start of this project with tweaking the names a bit, and I'm wishing I had primarily focused on sticking to the PEG names for this phase, even if we rename them later (which we will).

Short work session today.

### 8-28-2024
Confirmed from Discord and a bit of experimentation that the last pair choice is simply `seq('=', $.Id)`. The pair_sugar in the PEG is there to make `a = { = b }` and `a = { b = b }` return the same ast (and a reminder you can run `nelua --print-ast example_whatever.nelua` to see the AST from the PEG parser).

- [x] Finish first pass at type expressions and everything related
- [x] Find and implement variable assignment, and then attempt to get everything running. This should allow us to do test passes on each type declaration.
  - In the PEG, variable assignment starts at the Assign rule 
  - [x] Assign is part of the Statements section, which we've already started, so let's continue that for now
    - ForNum seems a bit weird, I'm not quite sure how to read the ~? syntax, optional capture. I think it's used to fill a node with a nil value if its not found. We'll need to do some extra testing in this area though.

At the end of this work session, I've got a first pass completed for everything in the Statement section. I think I'm missing `suffixeddecls`, but most dependency rules I was able to implement.

### 8-27-2024
It's easy when following the PEG to keep diving into the syntax and finding yourself writing too much code without running any tests. I've added a rule called "temporary_expression" that can be read off the top level, which should give me a place to comment/uncomment in test rules.

I became fairly annoyed today at the "Unedefined symbol" error, which I believe is caused when you reference a rule that has yet to be defined. The error gives 0 actual useful information though on which symbol was undefined or what line its on.

This issue has been marked as resolved on July 5th by https://github.com/tree-sitter/tree-sitter/pull/3452 but I may not yet have the correct version, so I'll be looking to upgrade or use master today.

Updating to 0.23.0 resulted in a much better error message.


After trying out the approach of using temporary_expression to surface deep rules, I ran into problems with it finding conflicts that I think only exist because we are trying to surface those rules. So this approach doesn't actually work too well. I think I'll return to just filling in rules, and perhaps running a bit more often. Focusing on getting the Return rule working may be a good way to test a lot of nested rules (its used in the PEG tests quite a bit).

- [x] Figure out how to get better error message
- [x] Fix existing missing/broken rules
- [x] Add typeexprunary
- [x] Add Pair
  - I asked about how to read the pair_sugar portion of the PEG in the Nelua discord, for now I only have the first two options implemented
- [x] Get running again

### 8-26-2024
Going a bit broad today, sketching out a bunch of stuff straight out of the PEG.  Didn't really reference any other tree-sitters today, just trying to get a bunch of rules added with their corresponding PEG info. This will certainly leave everything in a broken state. Once most of the type declarations have a first pass done, it's likely I'll try and figure out a way to test those.

- [ ] Preprocess expression
- [x] Simple expressions: Varargs
