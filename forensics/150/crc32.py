#!/usr/bin/env python

POLYNOMIAL=0xedb88320
POLYNOMIAL2=0x04c11db7

def reverse(num):
    num = ((num & 0x55555555) << 1) | ((num >> 1) & 0x55555555)
    num = ((num & 0x33333333) << 2) | ((num >> 2) & 0x33333333)
    num = ((num & 0x0f0f0f0f) << 4) | ((num >> 4) & 0x0f0f0f0f)
    num = (num << 24) | ((num & 0xff00) << 8) | ((num >> 8) & 0xff00) | (num >> 24);
    return num

def crc32(msg):
    crc = 0xffffffff
    
    for c in msg:
        c = ord(c)
        c = reverse(c)
        for j in range(8):
            if (crc ^ c) < 0:
                crc = (crc << 1) ^ POLYNOMIAL2
            else:
                crc = crc << 1;
            c = c << 1
    return reverse(~crc)

if __name__=="__main__":
    import sys
    print hex(reverse(0b10101010101010101010101010101010))
    print hex(crc32('IHDR'))
