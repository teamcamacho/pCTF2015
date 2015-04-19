#!/usr/bin/env python

import struct
import binascii
import png
import zlib

def crc32(header, data):
    cksum = zlib.crc32(header)
    return zlib.crc32(data, cksum)



#with open("corrupt_735acee15fa4f3be8ecd0c6bcf294fd4.png", "rb") as f:
#with open("testing.png", "rb") as f:
with open("out.png", "rb") as f:

    f.seek(0, 2)
    file_size = f.tell()
    f.seek(0)
    header = f.read(8)


    while f.tell() < file_size:

        chunk_size = binascii.hexlify(f.read(4))
        #print "Chunk size: ", chunk_size

        chunk_type = f.read(4)
        #print "Chunk type: ", chunk_type

        chunk_data = f.read(int(chunk_size, 16))

        chunk_crc = struct.unpack('>i', f.read(4))[0]
        #print "Chunk crc: 0x%x" % chunk_crc

        calc_crc = crc32(chunk_type, chunk_data)
        #print "Calculated crc: ", hex(calc_crc)

        #if chunk_crc != calc_crc:
        print "Invalid CRC"
        print "Chunk size: ", chunk_size
        print "Chunk type: ", chunk_type
        #print "Chunk data: ", binascii.hexlify(chunk_data)
        #print "Chunk data: ", binascii.b2a_uu(chunk_data[len(chunk_data)-12])
        print "Chunk crc: 0x%x" % chunk_crc
        print "Calculated crc: ", hex(calc_crc)
        
        print hex(f.tell())


