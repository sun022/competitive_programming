#!/bin/bash
echo "Switching to project '$1'."

export PROJ="$1"

if [ ! -d "$PROJ" ]; then
    echo "Creating new directory."
    mkdir -p "$PROJ/"
    cp "template.cpp" "$PROJ/source.cpp"
fi

code "$PROJ/a.txt"
code "$PROJ/source.cpp"
