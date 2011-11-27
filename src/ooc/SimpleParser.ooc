import Data
import Parser
import ProgramObject
import CodeSection
import ISARegistry
import Statement
import Instruction
import RegisterData
import io/FileReader
import structs/ArrayList
import lang/IO

SimpleParser: class extends Parser {
  parse: func(fileName: String) -> ProgramObject {
    statements := ArrayList<Statement> new()

    reader := FileReader new~withName(fileName) 
    isa_name := reader readLine()
    isa := ISARegistry.lookup(isa_name)
    while (reader hasNext?()) {
      line := reader readLine()
      trimmed := line trim~whitespace()
      ("Read line: '" + trimmed + "'") println()
      if (trimmed empty?()) {
        "empty" println()
      } else {
        "not empty" println()
        printf("%i %i ---- \n", trimmed length(), trimmed[0])
      }
      if (!(line trim~whitespace() trim(0 as Char) empty?())) {
        statements.add(parseStatement(line))
      }
    }
    return ProgramObject new(CodeSection new(statements))
  }

  parseStatement: func (line: String) -> Statement {    
    op := CString new~withLength(200)
    arg1 := CString new~withLength(200)
    arg2 := CString new~withLength(200)
    sscanf(line as CString, "%s %s %s", op, arg1, arg2)
    args:= ArrayList<Data> new()
    args add(RegisterData new(arg1 toString(), 1))
    args add(RegisterData new(arg2 toString(), 1))

    stmt := Statement new(Instruction new(op toString()))
    stmt args = args
    return stmt
  }
}
