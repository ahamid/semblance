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

SimpleParser: class extends Parser {
  parse: func(fileName: String) -> ProgramObject {
    statements := ArrayList<Statement> new()

    reader := FileReader new~withName(fileName) 
    isa_name := reader readLine()
    isa := ISARegistry.lookup(isa_name)
    while (reader hasNext?()) {
      statements.add(parseStatement(reader readLine()))
    }
    return ProgramObject new(CodeSection new(statements))
  }

  parseStatement: func (line: String) -> Statement {    
    //op: String
    //arg1: String
    //arg2: String
    //line scanf("%s %s %s", &op, &arg1, &arg2)
    //blargs:= ArrayList<Data> new()
    //args add(RegisterData new(arg1, 1))
    //args add(RegisterData new(arg2, 1))
    ins := Instruction new("foo")
    
    stmt := Statement new(ins)

    //stmt.ins = ins
    //stmt.args = blargs
    return stmt
  }
}
