#!/bin/bash

[ -d target ] && rm -r target
mkdir target && (cd target && cmake ..)
