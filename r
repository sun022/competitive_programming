#!/bin/bash

if [ ! "$PROJ" ]; then
    echo "No project."
    exit
fi

g++ -std=c++17 -O2 "$PROJ/source.cpp" -o "$PROJ/a.exe" || exit
"./$PROJ/a.exe" < "$PROJ/a.txt"
