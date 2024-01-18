from socket import *
import os
import sys
import struct
import time
import select
import binascii

ICMP_ECHO_REQUEST = 8
timeRTT = []
packageSent =0
packageRev = 0

def checksum(s):
    csum = 0
    countTo = int((len(s) / 2) * 2)
    
    count = 0
    while count < countTo:

        thisVal = s[count+1] * 256 + s[count]
        csum = csum + thisVal
        csum = csum & 0xffffffff
        count = count + 2
    if countTo < len(s):
        csum = csum + ord(s[len(s) - 1])
        csum = csum & 0xffffffff
    csum = (csum >> 16) + (csum & 0xffff)
    csum = csum + (csum >> 16)
    answer = ~csum
    answer = answer & 0xffff
    answer = answer >> 8 | (answer << 8 & 0xff00)
    return answer

def receiveOnePing(mySocket, ID, timeout, destAddr):
    global packageRev,timeRTT
    timeLeft = timeout
    while 1:
        startedSelect = time.time()
        whatReady = select.select([mySocket], [], [], timeLeft)
        howLongInSelect = (time.time() - startedSelect)
        if whatReady[0] == []: # Timeout
            return "Request timed out."
        timeReceived = time.time()
        recPacket, addr = mySocket.recvfrom(1024)

    #Fill in start
        #Fetch the ICMP header from the IP packet
        icmpHeader = recPacket[20:28]
        requestType, code, revChecksum, revId, revSequence = struct.unpack('bbHHh',icmpHeader)
        if ID == revId:
            bytesInDouble = struct.calcsize('d')
            timeData = struct.unpack('d',recPacket[28:28 + bytesInDouble])[0] 
            timeRTT.append(timeReceived - timeData)
            packageRev += 1
            return timeReceived - timeData
        else:
            return "ID does not match"
        #Fill in end

        timeLeft = timeLeft - howLongInSelect
        if timeLeft <= 0:
            return "1: Request timed out."

def sendOnePing(mySocket, destAddr, ID):
    global packageSent
    myChecksum = 0
    header = struct.pack("bbHHh", ICMP_ECHO_REQUEST, 0, myChecksum, ID, 1)
    data = struct.pack("d", time.time())
    myChecksum = checksum(header + data)

    if sys.platform == 'darwin':
        myChecksum = htons(myChecksum) & 0xffff
    else:
        myChecksum = htons(myChecksum)

    header = struct.pack("bbHHh", ICMP_ECHO_REQUEST, 0, myChecksum, ID, 1)
    packet = header + data

    mySocket.sendto(packet, (destAddr, 1))
    packageSent += 1


def doOnePing(destAddr, timeout):
    icmp = getprotobyname("icmp")
    mySocket = socket(AF_INET, SOCK_RAW, icmp)

    myID = os.getpid() & 0xFFFF  #Return the current process i
    sendOnePing(mySocket, destAddr, myID)
    delay = receiveOnePing(mySocket, myID, timeout, destAddr)
    mySocket.close()
    return delay

def ping(host, timeout=1):
    #timeout=1 means: If one second goes by without a reply from the server,
    #Send ping requests to a server separated by approximately one second
    dest = gethostbyname(host)
    print("Pinging " + dest +" / "+host+ " using Python:")
    print("")
    while 1 :
        delay = doOnePing(dest, timeout)
        print("Delay:",delay)
        time.sleep(1)# one second
    return delay

ping("google.com")