def my_hash(string):
    x = ord(string[0]) << 7
    for c in string:
        x = (1000003 * x) ^ ord(c)
    x ^= len(string)
    needCorrection =  x & (1 << 65)
    x %= 2 ** 64
    if needCorrection:
        x = -~(-x ^ 0xFFFFFFFFFFFFFFFF)
    if x == -1:
        x = -2
    return x
