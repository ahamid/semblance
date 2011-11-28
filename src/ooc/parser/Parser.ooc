import ProgramObject
include parser
include token

TT: extern(TokenType) enum {}

TokenStruct: cover from Token {
  type: TT
  value: extern String
}

ParserCallbacksStruct: cover from ParserCallbacks {
  createArg: extern func(owner: Pointer, token: TokenStruct)
}

Parser: abstract class {
  parse: abstract func(file: String) -> ProgramObject
}
