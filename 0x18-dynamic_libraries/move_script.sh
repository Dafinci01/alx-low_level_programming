#!/bin/bash

# List of function names to search for
function_names=(
    "_putchar"
    "_islower"
    "_isalpha"
    "_abs"
    "_isupper"
    "_isdigit"
    "_strlen"
    "_puts"
    "_strcpy"
    "_atoi"
    "_strcat"
    "_strncat"
    "_strncpy"
    "_strcmp"
    "_memset"
    "_memcpy"
    "_strchr"
    "_strspn"
    "_strpbrk"
    "_strstr"
)

# Loop through the function names
for func in "${function_names[@]}"; do
    # Find the files containing the function and copy them to the destination directory
    find . -type f -name "*.c" -exec grep -l "$func" {} \; -exec cp {} "0x18-dynamic_libraries/" \;
done

echo "Copied all relevant C files to folder"

