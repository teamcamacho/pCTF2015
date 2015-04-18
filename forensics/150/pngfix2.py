#!/usr/bin/env python
import ctypes
import struct
import binascii
import png
import zlib
import mmap

def crc32(chunk_type, chunk_data):
    cksum = zlib.crc32(chunk_type)
    return zlib.crc32(chunk_data, cksum)

def fixcrc(chunk_type, chunk_data, expectedcrc):
    print "Trying to fix crc"

    print "Original tail: ", binascii.hexlify(chunk_data[len(chunk_data)-4:])

    for i in range(0xff):
        newdata = chunk_data + chr(i)
        #newdata = chr(i) + chunk_data
        print "New tail: ", binascii.hexlify(newdata[len(newdata)-5:])
        newcrc = crc32(chunk_type, newdata)
        print hex(newcrc)
        if newcrc == expectedcrc:
            print "!! found missing char: %x" % i
            return

headers = ["IHDR", "sBIT", "pHYs", "tEXt", "IDAT", "IEND"]

with open("corrupt_crc_3.png", "rb") as f:
#with open("testing.png", "rb") as f:
#with open("out.png", "rb") as f:
    s = mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)

    f.seek(0, 2)
    file_size = f.tell()
    f.seek(0)
    header = f.read(8)
    nexthexists = True

    while f.tell() < file_size:

        # Get chunk size
        chunk_size = binascii.hexlify(f.read(4))
        #print "Chunk size: ", chunk_size

        # Get chunk type
        chunk_type = f.read(4)
        print "Chunk type: ", chunk_type

        # Locate next header
        indices = [s.find(h, f.tell()) for h in headers]

        try:
            nexth = min(i for i in indices if i > -1)
        except ValueError:
            nexthexists = False
       
        #print
        #print "len(s): ", len(s)
        #print "f.tell(): ", f.tell()
        #print "nexth: ", nexth
        #print
 
        print "Chunk size: ", chunk_size

        if nexthexists:
            print "Correct size: ", hex(nexth - f.tell() - 8)
            print "Difference: ", hex(nexth - f.tell() - 8 - int(chunk_size,16))

            chunk_data = f.read(nexth - f.tell() - 8)
            chunk_crc = struct.unpack('>i', f.read(4))[0]
        else:

            chunk_data = f.read(int(chunk_size,16))
            chunk_crc = struct.unpack('>i', f.read(4))[0]
        chunk_ucrc = ctypes.c_uint(chunk_crc)
        print "Chunk crc: 0x%x" % chunk_ucrc.value

        calc_crc = crc32(chunk_type, chunk_data)
        u_crc = ctypes.c_uint(calc_crc)
        print "Calculated crc: 0x%x" %(u_crc.value)

        """
            if chunk_crc != calc_crc:
            print "Invalid CRC"
            #print "Chunk size: ", chunk_size
            #print "Chunk type: ", chunk_type
            #print "Chunk data: ", binascii.hexlify(chunk_data)
            #print "Chunk data: ", binascii.b2a_uu(chunk_data[len(chunk_data)-12])
            #print "Chunk crc: 0x%x" % chunk_crc
            #print "Calculated crc: ", hex(calc_crc)
            
            #print hex(f.tell())

            fixcrc(chunk_type, chunk_data, chunk_crc)
        """

        print "--------------"
