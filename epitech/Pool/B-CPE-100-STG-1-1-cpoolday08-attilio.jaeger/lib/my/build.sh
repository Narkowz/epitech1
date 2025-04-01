#!/bin/bash
rm libmy.a
gcc -c *.c
ar rc libmy.a *.o
rm *.o
