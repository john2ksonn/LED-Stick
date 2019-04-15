#!/data/data/com.termux/files/usr/bin/sh

termux-storage-get input
python3 img2hex.py > output.hex
termux-share -a send output.hex
