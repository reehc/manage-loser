#! /bin/bash

# compile c to assembly every 0.5 second!
# Am I abuse my computer?!

# I am using this with Emacs
# M-x auto-revert-mode to enable this mode
# set reload-internal... something like this to a low value.

while sleep 0.5
do
    gcc -S -O2 *.c
    sed -i '/^\t\./ d' *.s
	sed -i '/^\./ d' *.s
done
