import ISA
import Datum
import structs/ArrayList

FakeISA: class extends ISA {
  name: func -> String {
    return "fake"
  }
  registers: func -> Register[] {
    return [] as Register[]
  }
  push: func(datum: Datum) {
  }
  pop: func(size: Int, reg: Register) {
  }
}
