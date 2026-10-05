#!/bin/bash

package=show-example-0.1
work=$(mktemp -d)
mkdir -p "$work/$package"

cp ../01_TerminalProject/Show.c \
   ../01_TerminalProject/Makefile \
   "$work/$package/"

tar -czf $package.tar.gz \
    -C "$work" $package

tar -tzf $package.tar.gz