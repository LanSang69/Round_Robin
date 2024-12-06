#!/bin/bash

cd /home/lansan69/projects/Round_Robin

if [ -z "$1" ]; then
    echo "Please provide the name of the program."
    exit 1
fi

PROGRAM_NAME=$1

gcc $1 -o ejecutable `pkg-config --cflags --libs gtk+-3.0` && ./ejecutable

if [ $? -eq 0 ]; then
    ./your_gtk_program
else
    echo "Compilation failed."
fi