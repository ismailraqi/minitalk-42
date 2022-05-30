#!/bin/bash
make && make clean
./server &
sleep 1
./client $(pgrep server | sed -n 2p) "$1"