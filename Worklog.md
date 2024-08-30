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
- [ ] Simple expressions: Id and IdDecl
  - [ ] typeexpr
    - [ ] typeexprunary
    - [ ] typevaris
    - [ ] typeopunary
    - [ ] typeexprsimple
    - [ ] typeexprprim
  - [ ] annots
- [ ] Types
