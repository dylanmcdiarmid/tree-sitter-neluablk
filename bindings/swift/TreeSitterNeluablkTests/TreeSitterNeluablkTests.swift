import XCTest
import SwiftTreeSitter
import TreeSitterNeluablk

final class TreeSitterNeluablkTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_neluablk())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Neluablk grammar")
    }
}
