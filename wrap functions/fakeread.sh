#!/bin/bash

gcc -D_GNU_SOURCE -shared -fPIC fakeread.c -o libfakeread.so -ldl
LD_PRELOAD=./libfakeread.so cat /etc/hostname
