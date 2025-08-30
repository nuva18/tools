#!/bin/sh

if [ $# -ne 1 ]; then
    echo "usage: keyme <filename>" 
    echo "       Creates a new ssh key." 
    exit 1
fi

priv_key=$HOME/.ssh/$1
pub_key=$priv_key.pub

ssh-keygen -t ed25519 -b 4096 -f $priv_key 

echo
echo "Done. Here's your public key:"
cat $pub_key
exit 0
