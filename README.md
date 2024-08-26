# tree-sitter-neluablk
Started as just an implementation of parsing the multiline blocks in the Nelua language (which require the C plugin features of tree-sitter, scanner.c).
Eventually this will be a complete tree-sitter implementation of Nelua with a full test suite.

Currently a work in progress, everything is quite messy and will remain that way until the cleanup phase.

# Phases

### Phase 1
**COMPLETE**

Implement comment multiline blocks, string multiline blocks, and pre-processor 
multiline blocks. Both comment and pre-processor should be tokenized in a way that 
allows for injection of other languages. This means we need to maintain state so that 
the beginning and ending tokens are separated from the body (first implementation was stateless).

## Phase 2 - grammar.js
_Incomplete_

Implement the rest of the grammar.js, following the Nelua PEG grammar, while attempting to adjust to the needs of an LR parser. I want to create an AST 
suited to syntax highlighting rather than copying what makes sense for Nelua.

Basic testing will be done during this phase by running `tree-sitter parse` on example files. AST is not final.

Tracking features as they are completed in: [features.md](features.md)

## Phase 3 - Queries/Tests
_Incomplete_

At this point the major features will be implemented, and I'll start cleaning up the AST, adding
fields where they make sense, and in general making sure everything is well organized for its
primary purpose.

## Phase 4 - Cleanup/Finalization
_Incomplete_

At this point I'll start comparing the project to other well regarded tree-sitter projects
and attempt to get it into a state where I can turn it over to the tree-sitter organization,
whatever that entails.

