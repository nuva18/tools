#!/bin/sh

if [ $# -ne 1 ]; then
    echo "usage: keyme <filename>" 
    echo "       Creates a new ssh key." 
    exit 1
fi

ssh-keygen -t ed25519 -b 4096 -f /home/$USER/.ssh/$1

echo
echo "Done. Here's your public key:"
cat $HOME/.ssh/$1.pub
exit 0
