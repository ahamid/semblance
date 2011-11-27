import Instruction
import Data

Statement: class {
  ins: Instruction
  args: Iterable<Data>

  init: func (=ins) {}
}
