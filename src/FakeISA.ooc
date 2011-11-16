import ISA
import Datum

FakeISA: class extends ISA {
  name: func -> String {
    return "fake"
  }
  registers: func -> Register[] {
    return null //[] as Register[]
  }
  push: func(datum: Datum) {
  }
  pop: func(size: Int, reg: Register) {
  }
}
