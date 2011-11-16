import Parser
import ProgramObject
import ISARegistry
import io/FileReader

SimpleParser: class extends Parser {
  parse: func(fileName: String) -> ProgramObject {
    reader := FileReader new~withName(fileName) 
    fileName println()
    isa_name := reader readLine()
    isa := ISARegistry.lookup(isa_name)
    while (reader hasNext?()) {
      reader readLine() println()
    }
    return null
  }
}
