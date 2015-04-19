#!/usr/bin/env python

# length location: 0x6d
# good length: 0x1fffe

with open("corrupt_735acee15fa4f3be8ecd0c6bcf294fd4.png", "rb") as f:
    
    with open("out.png", "wb") as fo:

        fo.write(f.read(0x6d))
        fo.write("\x00\x02\x00\x00")
        print hex(f.tell())
        #f.seek(0x71)
        f.seek(0x71)
        fo.write(f.read(0x00020004))
        fo.write(f.read())

