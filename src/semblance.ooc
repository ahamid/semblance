import elf

import SimpleParser

import structs/ArrayList

/*main: func {
  "bar" println()
}*/
main: func(args: ArrayList<String>) {
  "foo" println()
  //e: Elf@
  args[0] println()
  args[1] println()
  parser := SimpleParser new()
  parser parse(args[1])
}
