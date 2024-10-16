#!/bin/sh

if [ $# -ne 2 ]; then
    echo "usage: gituser <name> <email>"
    echo "       Changes the local git user."
    exit 1
fi

# <username>@users.noreply.github.com

git config --local user.name "'$1'"
git config --local user.email $2

exit 0
