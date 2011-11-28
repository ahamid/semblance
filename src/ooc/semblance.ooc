import elf
import parser/SimpleParser
import structs/ArrayList
import ProgramObject
import Statement
import Instruction
import CodeSection
import RegisterData

/*main: func {
  "bar" println()
}*/
main: func(args: ArrayList<String>) {
  //e: Elf@
  args[1] println()
  parser := SimpleParser new()
  obj := parser parse(args[1])
  for (stmt in obj codeSection statements) {
    "ins: " print()
    stmt ins code println()
    for (arg in stmt args) {
      "arg: " print()
      (arg as RegisterData) registerName println()
    }
  }
}
