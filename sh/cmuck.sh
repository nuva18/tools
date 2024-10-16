#!/bin/sh

if [ $# -ne 2 ]; then
    echo "usage: cmuck <input> <output>"
    echo "       Automatically redirects cmark output to a file."
    exit 1
fi

cmark $1 > $2
exit 0
