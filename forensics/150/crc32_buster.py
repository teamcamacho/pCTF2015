import zlib
import binascii
import ctypes
'''
CRC32 should be 7EC18F9Eh
'''


def main(arg):
	with open("C:/Users/user/Documents/Visual Studio 2013/Projects/pCTF2015/forensics/150/test_crc_binary_second_byte.bin", "rb") as fi:
		data = fi.read()
		b = bytearray(data)
		for x in range(0, 256):
			# data[0] = 0x00
			b[len(data) - 1] = x
			d = binascii.a2b_hex(binascii.hexlify(b[4:0x20004]))
			# calculate tag crc
			tag_crc = binascii.crc32(b[0:4])

			item = ctypes.c_ulong(zlib.crc32(d, tag_crc))
			item2 = ctypes.c_ulong(zlib.crc32(d))
			# print "0x%s"%binascii.hexlify(d)
			final_crc = "%x" % item.value
			# if arg in final_crc:
			print "%s" % binascii.hexlify(d[len(d) - 4:len(d)])
			print "final crc is 0x%x" % (item.value)
				# print "final crc without tag is 0x%x"%(item2.value)
			# print "%s"%binascii.hexlify(d[0x1fffc:0x20000])
		# b.append(data)
		# print "0x%s"%binascii.hexlify(b)


		print "data length is 0x%x" % (len(data) - 4)
	pass
def add_test():
	with open("C:/Users/user/Documents/Visual Studio 2013/Projects/pCTF2015/forensics/150/test_compression_testdata.bin", "rb") as fi:
		data = binascii.hexlify(fi.read())
		b = bytearray(data)
		print "data length is %d"%len(b)
		print "data is %s"%b
		
		b.append("1")
		print "data length is %d"%len(b)
		print "data is %s"%b
		
def decomp_test():
	with open("C:/Users/user/Documents/Visual Studio 2013/Projects/pCTF2015/forensics/150/test_compression_testdata.bin", "rb") as fi:
		data = binascii.hexlify(fi.read())
		print "data length is %d"%len(data)
		print "data is %s"%data
		
		idat = binascii.unhexlify(data)
		print "idat length is %d"%len(idat)
		
		cpr = zlib.decompress(idat)
		print "cpr length is %d"%len(cpr)
		
		print "==testdata=="
		print "%s"%binascii.hexlify(cpr)
		print "==testdata=="

def decomp():
	with open("C:/Users/user/Documents/Visual Studio 2013/Projects/pCTF2015/forensics/150/test_compression.bin", "rb") as fi:
		z = zlib.decompressobj()

		# data = binascii.hexlify(fi.read())
		# idat = binascii.unhexlify(data)
		# # print "%s"%data
		# cpr = zlib.decompress(idat)
		get =""
		# fi.read(4)
		
		""" 
		Get the whole decompression blob
		"""
		data = fi.read()
		b = bytearray(data)
		for i in range(0,4):
			print "len of b was: %d"%len(b)
			print "i was %d"%i
			b.append(0)
			print "len of b is: %d"%len(b)
		
			for x in range(0,256):
			# b[len(b)-1] = x
			# print "last bit was %s"%binascii.hexlify(b[len(b)-4:len(b)])
				hex_b = binascii.hexlify(b)
				un_b = binascii.unhexlify(hex_b)
				try:
					zlib.decompress(un_b)
					print "yay"	
				except:
					continue
		
		""" 
		Get the partial decompression blob
		"""
		while True:
			buf = z.unconsumed_tail
			if buf == "":
				buf = fi.read(8192)
				print "buf len is 0x%x"%len(buf)
				if buf == "":
					break
			got = z.decompress(buf)
			if got == "":
				break
			get = get+binascii.hexlify(got)
		if len(get) > 4:
			cdata = zlib.compress(get)
			ddata = zlib.decompress(cdata)
			print "you got got with %d bytes"%len(get)
if __name__ == "__main__":
	# pass
	# add_test()
	# decomp_test()
	decomp()
	# main("adefb326")
