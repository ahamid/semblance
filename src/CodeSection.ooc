import Statement

CodeSection: class {
  statements: Iterable<Statement>
  init: func () {}
  init: func ~withStatements (=statements) {}
}
