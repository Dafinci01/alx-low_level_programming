#!/bin/bash
gcc -c -wall -Werror -fPIC  *.c

gcc -shared -o liball.so -fPIC *.o
