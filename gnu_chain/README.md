# gcc
useful options:
     `-I and -D`

NOT UNDERSTAND:
     `gcc -c -g -Wa,-ahl,-L test.c`

`-Wall` (synonym) `-all-warnings`
add a `-Wno-unused` to disable
Also other warnings not in `-Wall`

`-OO`: no optimization, good for gdb
`-O`, `-O1`: a safe level 
     `-f`: specify optimizations explicitly, 
         `-fdefer-pop` <=> `-fno-defer-pop`
`-O2`: speed!
`-Os`: smaller exectable...
`-O3`: highest level

Architectual optimization:
  `-mcpu=i386`(default)

DEBUG: `-gdwarf-2`(dwarf-2 format)

$ size test.o
$ objdump -syms test.o
$ objdump -disassemble test.o
$ nm

# make
$(func arg1,arg2,...)
$(subst before,after,${VAR})	substitute
$(patsubst t%t,T%T,${VAR})	
${filter %ing %able,${VAR}}
${sort ${VAR}}			lexical order sorting
${words {VAR}}			word count
${word 7,${VAR}}		numerical indexing
${wordlist 2,3,${VAR}}		substring
${addprefix src/, ${HEADERS}}