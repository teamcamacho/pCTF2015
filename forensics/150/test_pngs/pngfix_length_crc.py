#!/usr/bin/env python
import ctypes
import struct
import binascii
import zlib
import mmap

def crc32(chunk_type, chunk_data):
    cksum = zlib.crc32(chunk_type)
    return zlib.crc32(chunk_data, cksum)

def main(infilename, outfilename):

    headers = ["IHDR", "sBIT", "pHYs", "tEXt", "IDAT", "IEND"]

    with open(infilename, "rb") as f:
        s = mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)

        newdata = [b for b in f.read()]

        f.seek(0, 2)
        file_size = f.tell()
        f.seek(0)
        header = f.read(8)
        nexthexists = True

        while f.tell() < file_size:

            # Get chunk size
            chunk_size = binascii.hexlify(f.read(4))

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
                chunk_correct_size = nexth - f.tell() - 8
                print "Correct size: ", hex(chunk_correct_size)
                #chunk_size_diff = nexth - f.tell() - 8 - int(chunk_size,16)
                chunk_size_diff = abs(nexth - f.tell() - 8 - int(chunk_size,16))
                print "Difference: ", hex(chunk_size_diff)


                for i in range(chunk_size_diff):
                    print "Adding byte"
                    newdata.append("\x00")
                    x = len(newdata) - 1
                    while x > f.tell():
                        newdata[x] = newdata[x-1]
                        x -= 1
                    newdata.insert(f.tell(), "\x00")
                
                """
                if chunk_correct_size != int(chunk_size,16):
                    b1,b2,b3,b4 = [chr(chunk_correct_size >> i & 0xff) for i in (24,16,8,0)]
                    newdata[f.tell() - 8] = b1
                    newdata[f.tell() - 7] = b2
                    newdata[f.tell() - 6] = b3
                    newdata[f.tell() - 5] = b4
                """

                chunk_data = f.read(nexth - f.tell() - 8)
            else:
                chunk_data = f.read(int(chunk_size,16))

            # Get chunk crc
            chunk_crc = ctypes.c_uint(struct.unpack('>i', f.read(4))[0]).value
            print "Chunk crc: 0x%x" % chunk_crc

            # Calculate our own crc
            calc_crc = crc32(chunk_type, chunk_data)
            u_crc = ctypes.c_uint(calc_crc)
            print "Calculated crc: 0x%x" %(u_crc.value)

            if chunk_crc != calc_crc:
                """
                fixcrc(chunk_type, chunk_data, chunk_crc)
                """
                b1,b2,b3,b4 = [chr(u_crc.value >> i & 0xff) for i in (24,16,8,0)]
                newdata[f.tell() - 4] = b1
                newdata[f.tell() - 3] = b2
                newdata[f.tell() - 2] = b3
                newdata[f.tell() - 1] = b4
                

            print "--------------"

    with open(outfilename, "wb") as f:
        f.write("".join(newdata))

if __name__=="__main__":
    import sys
    if len(sys.argv) != 3:
        print "%s <original png file> <new png file>" % sys.argv[0]
        sys.exit()

    main(sys.argv[1], sys.argv[2])

