#!/bin/bash
# make fclean && make && make clean
# ./server &
# sleep 2
# ./client $(pgrep server | sed -n 2p) "$1"
make fclean && make && make clean
./server &
sleep 2
./client $(pgrep server | sed -n 2p) "$1"
sleep 2
./client $(pgrep server | sed -n 2p) "$1"
sleep 2
./client $(pgrep server | sed -n 2p) "$1"