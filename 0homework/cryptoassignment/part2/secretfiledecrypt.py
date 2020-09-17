# Notes?
# AHHHHH
# Key shampt 1 = fZcN v x B W E b D s
# also in key is D,s,v,x,B, W, E, b  


# Rotate: ( ((val >> n) | (val << (8-n)))&0xff )

letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
lowercase = "abcdefghijklmnopqrstuvwxyz" 
hexstuff = "\x1f\x8b\x08\x08"
#XOR = "Z"


with open("secretfile.txt.gz.enc", "rb") as infile:
    data = infile.read()


#print(hex(data[0]))
#shampt = 1
#for x in letters:
#    xord = data[2] ^ ord(x) 
#    print(shampt, end = " ")
#    print(x, end = " ")
#    print(hex( ( ((xord >> shampt) | (xord << (8-shampt)))&0xff ) ))

#for x in range(65, 122):
#    for i in range(7):
#        xord = data[2] ^ x
#        print(chr(x), end = " ")
#        print(i, end = " ")
#        print(hex( ( ((xord >> i) | (xord << (8-i)))&0xff ) ))

#for c in range(65,122):
#    for i in range(1,7):
#        xord = (data[3] ^ c)
#        rotated = (xord >> i) | (xord << 8-i) & 0xff
#
#        if rotated == 8:
#            print("Shift: ", end = " ")
#            print(i)
#            print("Key Letter: ", end = " ")
#            print(chr(c))
#            #print(chr(c), i)
#            #print(i)





for c in range(65,122):
    xord = data[23] ^ c
    rotated = (xord >> 1) | (xord << 8-1) & 0xff
    print(chr(c), end = " ")
    print(hex(rotated))
    #if rotated == 115:
    #    print(chr(c)) [16] == f
         
