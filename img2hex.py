#!/usr/bin/python3

from PIL import Image
from sys import stdout

im = Image.open("input")
maxSize = 9999999999, 144
im.thumbnail(maxSize)

pix = im.load()

for x in range(0, im.size[0]):
    for y in range(im.size[1]-1, -1, -1):
        for val in pix[x, y]:
            print("{:02x}".format(val), end="")

