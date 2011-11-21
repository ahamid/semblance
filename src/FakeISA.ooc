import ISA
import Data
import structs/ArrayList

FakeISA: class extends ISA {
  name: func -> String {
    return "fake"
  }
  registers: func -> ArrayList<Register> {
    return ArrayList<Register> new()
  }
  push: func(data: Data) {
  }
  pop: func(size: Int, reg: Register) -> Data {
    return null
  }
}
