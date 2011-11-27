import Data

MemoryData: class extends Data {
  location: Pointer
  init: func (=location, .size) {}
}
