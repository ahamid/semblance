import Datum
import structs/ArrayList

Register: class {
  name: String
  size: Int
}

ISA: abstract class {
  name: abstract func -> String
  registers: abstract func -> ArrayList<Register>
  push: abstract func(datum: Datum)
  pop: abstract func(size: Int, reg: Register) -> Datum
}
