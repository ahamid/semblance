include libelf

ElfCmd: cover from Elf_Cmd

Elf: cover from Void* {
  new: extern(begin) static func (filedes :Int, cmd :ElfCmd, ref :Elf@) -> Elf
}
