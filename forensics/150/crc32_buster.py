import zlib
import binascii
import ctypes
'''
CRC32 should be 0xf55a745d
'''
def main():
	with open("C:/Users/user/Documents/Visual Studio 2013/Projects/pCTF2015/forensics/150/test_crc_binary_first_byte.bin","rb") as fi:
		data = fi.read()
		b= bytearray(data)
		for x in range(0,255):
			# data[0] = 0x00
			b[0x20003] = x
			d = binascii.a2b_hex(binascii.hexlify(b))
			item = ctypes.c_ulong(binascii.crc32(d))
			print "0x%x"%(item.value)
			print "%s"%binascii.hexlify(d[0:0x10])
		# b.append(data)
		# print "0x%s"%binascii.hexlify(b)
		
		print "data length is 0x%x"%(len(data)-4)
	pass

if __name__ == "__main__":
    main()
