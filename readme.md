# Semblance

This is just a toy project I am developing to learn assembly a bit better.  I figured a good way to learn assembly was to write an assembler.  I'm using Zed Shaw's [EaRing](https://github.com/zedshaw/earing) as a guide, and implementing it in [ooc](http://ooc-lang.org) since it's a great compromise between high-level features and seamless integration with C.  No doubt this code is very amatuerish.

This project features:

* CMake build system with custom commands for Ragel and Lemon code generation (and eventually OOC/rock compilation)
* [Ragel](http://www.complang.org/ragel) for lexer
* [Lemon](http://www.hwaci.com/sw/lemon/index.html) for parser
* (maybe [libgc](http://www.hpl.hp.com/personal/Hans_Boehm/gc/))
