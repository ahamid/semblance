import ISA
import Data

CallingConvention: abstract class {
  // array of register or literal values
  // could just pass register but then wouldn't be able to provide literal values
  caller_setup: abstract func(isa: ISA, data: Data[])
  callee_setup: abstract func(isa: ISA, data: Data[])
  callee_teardown: abstract func(isa: ISA, data: Data[]) -> Data // return location
  caller_teardown: abstract func(isa: ISA, data: Data[])
}
