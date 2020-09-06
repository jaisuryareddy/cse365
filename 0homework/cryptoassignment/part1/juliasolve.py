import gzip

XORkey = "JDhkQeOpjVfy" * 1000
buffer = []
buffer2 = []



with open("juliaplaintext.txt.gz.enc", "rb") as in_file:
    data = in_file.read()


print("Raw Data: " + hex(data[0]))

for encData, key in zip(data,XORkey):
    x = (encData ^ ord(key))
    buffer.append(x)


print("Data XORD: " + hex(buffer[0]))


buffer = bytes(buffer)

for y in buffer:
    x = ( ((y >> 6) | (y << (8-6)))&0xff )
    buffer2.append(x)

print("Data Rotated: "+ hex(buffer2[0]))

buffer2 = bytes(buffer2)
with open("juliaSolved.txt.gz", "wb") as outfile:
    outfile.write(buffer2)






#
#with open("juliaSolved.txt.gz", "w") as out_file:
#    for x in buffer:
#        out_file.write((x >> 6) | ((x << (8-6)) & 0xff))





#with open("juliaXORD.txt.gz", "w") as outfile:
#    for encData, key in zip(data, XORkey):
#        outfile.write( chr(encData ^ ord(key)) )   
#
#with open("juliaXORD.txt.gz", "rb") as f:
#    dataf = f.read()
#
#with open("juliaSolved.txt.gz", "w") as mainOut:
#    for x in dataf:
#        mainOut.write( (x >> 6) | (x << (8 - 6)) & 0xff)





#with open("juliaXORD.txt", "rb") as f:
#    dataf = f.read()
#
#with open("juliasolved.txt", "w") as mainOut:
#    for x in dataf:
#        out.write()
        
