import Data
import Parser
import ProgramObject
import CodeSection
import ISARegistry
import Statement
import Instruction
import RegisterData
import io/File
import structs/ArrayList
import lang/Memory

LemonParser: class extends Parser {
  parse: func(fileName: String) -> ProgramObject {
    source := File new(fileName) read()
    source println()

    callbacks : ParserCallbacksStruct
    callbacks context = this
    callbacks createArg = This createArgCallback
    // TODO: figure out why i have to explicitly cast to CString
    // or add CString to extern declaration
    parse(source, callbacks&)
    "done parsing" println()
    return null
  }

  createArgCallback: func(token: TokenStruct@) -> Pointer {
    "IN CALLBACK" println()
    printf("%s\n", token value)
    (token value as String) println()
    return null
  }
}
