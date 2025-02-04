#!/bin/sh
set +e

# print who i am
id

# Setup any pre-load options
kenv hw.contigmem.buffer_size=10737418

# load contigmem
find . -name contigmem.ko -exec kldload {} \;

# Print contigmem options post load
sysctl -a

meson test -C build --suite fast-tests -t 3
