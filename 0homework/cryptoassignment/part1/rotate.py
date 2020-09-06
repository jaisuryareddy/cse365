
buffer = "ABCDEFGHIJKLM"
ch = buffer[0]
ch = ord(ch)
n = ch
d = 6

print(hex(ord(buffer[0])))


lrot = (ch << 6)|(ch >> (8 - 6))&0xff 

print("Left Rotated: " + hex(lrot))

rotated = (lrot >> 6)|(lrot << (8 - 6))&0xff

print("Right Rotate: " + hex(rotated))




