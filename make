#!/bin/sh

#rock -noclean -lelf -v -m64 -I. src/*.ooc -o=semblance
rock -lelf -v -m64 -I. src/*.ooc -o=semblance
