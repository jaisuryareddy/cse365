#Deven Pile - CSE365 F2020


with open("ciphertext.txt", "rb") as f:
    data = f.read()

with open("solvedcaesar.txt", "w") as out:
    for x in data:
        #out.write(chr(ord('A') + (data[x] - ord('A') - 23) % 26) )
        out.write(chr(((x - ord('A') - 23) % 26) + ord('A')))
