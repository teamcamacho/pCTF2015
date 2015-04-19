#!/usr/bin/env python
import ctypes
import struct
import binascii
import zlib
import mmap

def crc32(chunk_type, chunk_data):
    cksum = zlib.crc32(chunk_type)
    return zlib.crc32(chunk_data, cksum)

def shiftright(chunk_data, char):
    newdata = chr(char)
    chunk_size = len(chunk_data)

    for i in range(chunk_size):
        newdata += chunk_data[i]

    return newdata

def fixcrc(chunk_type, chunk_data, expectedcrc):
    print "Trying to fix crc"

    for i in range(0xff):
        #newdata = shiftright(chunk_data, i)
        newdata = chunk_data + chr(i)
        #print newdata.encode("hex")[:8], newdata.encode("hex")[-8:]
        #print chunk_data.encode("hex")[:8], chunk_data.encode("hex")[-8:]
        newcrc = crc32(chunk_type, newdata)

        if newcrc == expectedcrc:
            print "!! Fixed data !!"
            return

headers = ["IHDR", "sBIT", "pHYs", "tEXt", "IDAT", "IEND"]

def main(filename):
    with open(filename, "rb") as f:
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
           
            print "Chunk size: ", chunk_size

            if nexthexists:
                print "Correct size: ", hex(nexth - f.tell() - 8)
                print "Difference: ", hex(nexth - f.tell() - 8 - int(chunk_size,16))

                chunk_data = f.read(nexth - f.tell() - 8)

                if chunk_type == 'IHDR':
                    # Get compression method
                    comp_method = ctypes.c_ubyte(struct.unpack('B', chunk_data[11])[0]).value
                    print " + PNG compression method: ", bin(comp_method)

            else:

                chunk_data = f.read(int(chunk_size,16))


            # Get chunk crc
            chunk_crc = ctypes.c_uint(struct.unpack('>i', f.read(4))[0]).value
            print "Chunk crc: 0x%x" % chunk_crc

            # Calculate our own crc
            calc_crc = crc32(chunk_type, chunk_data)
            u_crc = ctypes.c_uint(calc_crc)
            print "Calculated crc: 0x%x" %(u_crc.value)

            if chunk_crc != u_crc.value:
                fixcrc(chunk_type, chunk_data, u_crc.value)

            print "--------------"

if __name__=="__main__":
    import sys
    if len(sys.argv) != 2:
        print "%s <png file>" % sys.argv[0]
        sys.exit()

    main(sys.argv[1])

