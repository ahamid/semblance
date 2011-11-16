import FakeISA
import ISA
import structs/HashMap

ISARegistry: class {
  isas := static HashMap<String, ISA>.new()
  register: static func(isa: ISA) {
    isas.add(isa.name(), isa)
  }
  lookup: static func(name: String) -> ISA {
    /*return isas.get(name)*/
    return FakeISA.new()
  }
}
