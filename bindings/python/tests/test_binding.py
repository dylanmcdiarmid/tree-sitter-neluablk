from unittest import TestCase

import tree_sitter, tree_sitter_neluablk


class TestLanguage(TestCase):
    def test_can_load_grammar(self):
        try:
            tree_sitter.Language(tree_sitter_neluablk.language())
        except Exception:
            self.fail("Error loading Neluablk grammar")
