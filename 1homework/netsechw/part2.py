import pyshark
import sys

sideChannel = pyshark.FileCapture(sys.argv[1])
#horizontal = pyshark.FileCapture(sys.argv[2])

print(sideChannel[1].tcp.ip.ttl)


#for side, hor in zip(sideChannel, horizontal):
#    try:
#        if( (side.flags.syn == 1) and (side.flags.ack == 1)):
#            if( (hor.flags.syn == 1) and (hor.flags.ack == 1)):
#                if(hor.ip != side.ip):
#                    print(hor.ip, " ", side.ip)
#    except:
#        continue
