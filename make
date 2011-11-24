#!/bin/bash -x

rm -r .libs rock_tmp
#rock -noclean -lelf -v -m64 -I. src/*.ooc -o=semblance
#rock -lelf -m64 -Isrc -o=semblance src/semblance.ooc
rock -m64 -Isrc -o=semblance src/semblance.ooc $@
