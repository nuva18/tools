#!/bin/sh

if [ $# -eq 0 ]; then
    echo "usage: calc <expression>"
    echo "       Calculates the expression using awk."
    exit 1
fi

j=`echo "$*" | sed 's/xor/\^/g' | sed 's/x/\*/g'`
echo "" | awk 'BEGIN {print '"$j"'}'
