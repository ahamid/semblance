import Datum

Register: class {
  name: String
  size: Int
}

ISA: abstract class {
  registers: abstract func -> Register[]
  push: abstract func(datum: Datum)
  pop: abstract func(size: Int, reg: Register) -> Datum
}
