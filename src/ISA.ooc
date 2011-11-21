import Data
import structs/ArrayList

Register: class {
  name: String
  size: Int
  init: func (=name, =size) {}
}

ISA: abstract class {
  name: abstract func -> String
  registers: abstract func -> ArrayList<Register>
  push: abstract func(data: Data)
  pop: abstract func(size: Int, reg: Register) -> Data
}
