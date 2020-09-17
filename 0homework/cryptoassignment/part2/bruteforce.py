#Brute force lol
#rotate by - 14 works?
from  collections import Counter

with open("ciphertext.txt", "rb") as infile:
    data = infile.read()

#lc = Counter(data)
#print(lc)
with open("solvedCiphertext.txt", "w") as outfile:
    for x in data:
        outfile.write(chr(((x - ord('A') - 14 ) % 26) + ord('A')))


#print(ord('H') - ord('A'))

