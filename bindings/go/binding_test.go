package tree_sitter_neluablk_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_neluablk "github.com/tree-sitter/tree-sitter-neluablk/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_neluablk.Language())
	if language == nil {
		t.Errorf("Error loading Neluablk grammar")
	}
}
