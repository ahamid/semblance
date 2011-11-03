import ISA
import Datum

CallingConvention: abstract class {
  // array of register or literal values
  // could just pass register but then wouldn't be able to provide literal values
  caller_setup: abstract func(isa: ISA, data: Datum[])
  callee_setup: abstract func(isa: ISA, data: Datum[])
  callee_teardown: abstract func(isa: ISA, data: Datum[]) -> Datum // return location
  caller_teardown: abstract func(isa: ISA, data: Datum[])
}
