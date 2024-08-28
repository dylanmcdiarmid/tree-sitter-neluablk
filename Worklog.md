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
- [ ] Test $.Pair
- [ ] Test $.InitList
- [ ] Get running again
- [ ] Test RecordType
- [ ] Test UnionType

### 8-26-2024
Going a bit broad today, sketching out a bunch of stuff straight out of the PEG.  Didn't really reference any other tree-sitters today, just trying to get a bunch of rules added with their corresponding PEG info. This will certainly leave everything in a broken state. Once most of the type declarations have a first pass done, it's likely I'll try and figure out a way to test those.

- [ ] Preprocess expression
- [x] Simple expressions: Varargs
- [ ] Simple expressions: Id and IdDecl
  - [ ] typeexpr
    - [ ] typeexprunary
    - [ ] typevaris
    - [ ] typeopunary
    - [ ] typeexprsimple
    - [ ] typeexprprim
  - [ ] annots
- [ ] Types
