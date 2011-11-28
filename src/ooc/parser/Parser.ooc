import ProgramObject
include parser
include token

// C API
// #define MAX_VALUE_SIZE 2047
//
// typedef struct _Token {
//   int type;
//   char value[MAX_VALUE_SIZE + 1];
// } Token;

TokenStruct: cover from Token {
  type: extern Int // FIXME: should be TokenType enum
  value: extern CString
}

// C API 
// 
// typedef struct _ParserCallbacks {
//   void (*createArg)(void *, const Token* const tok);
// } ParserCallbacks;
//
// int parse(const char * const source, const ParserCallbacks * const);

ParserCallbacksStruct: cover from ParserCallbacks {
  //createArg: (extern func(token: TokenStruct*))*
  context: Pointer
  createArg: Pointer
}

// FIXME: why do I have to declare CString here or in caller
parse: extern func(source: CString, callbacks: ParserCallbacksStruct*) -> Int

Parser: abstract class {
  parse: abstract func(file: String) -> ProgramObject
}
