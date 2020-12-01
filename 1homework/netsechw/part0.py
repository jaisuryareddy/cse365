#python part0.py horizontal.pcap

import pyshark
import sys

pcap = pyshark.FileCapture(sys.argv[1])

for p in pcap:
    if p.transport_layer == 'UDP':
        if (int(p.udp.dstport) == 69):
            print(p)

                
            


#for p in pcap:
#  if p.transport_layer == 'UDP' and p.:
#      print(p)

#{'1036411689': 1022,
#  '0': 30,]
# '1454605540': 1, 
# '1036411690': 4, '
# 356529039': 1, 
# '3351072361': 1, 
# '1115649182': 1, 
# '1036477224': 1001, 
# '1019634217': 1, 
# '2861603725': 770, 
# '2861669260': 730, 
# '3714604571': 1022, 
# '2107423249': 1, 
# '3714604572': 3, 
# '2078295801': 1, 
# '1557562135': 1, 
# '3714670106': 1008, 
# '3697827611': 1, 
# '190739001': 770, 
# '190804536': 727}