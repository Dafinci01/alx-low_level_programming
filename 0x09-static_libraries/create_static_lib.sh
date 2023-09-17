#!/bin/bash
gcc -wall -pedantic -Werror -Wextra -c *.c
gcc -c *.c
ar rc liball.a *.o
ranlib liball.a
