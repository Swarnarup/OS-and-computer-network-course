import time
import socket
from time import sleep

# while True:
#     client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#     client_socket.settimeout(1.0)
#     inp = input("Enter q for QUES or end to exit")
#     if int == "end":
#         break
#     message = b'QUES'
#     addr = ("127.0.0.1", 12000)

#     start = time.time()
#     client_socket.sendto(message, addr)
#     sleep(2)
#     try:
#         data, server = client_socket.recvfrom(1024)
#         end = time.time()
#         elapsed = end - start
#         print(f'{data} {elapsed}')
#     except socket.timeout:
#         print('REQUEST TIMED OUT')



waiting = False
answering = False
max_timeout = 10
to=0

host='10.8.30.211' #client ip
port = 4008
# s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


while True:
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    client_socket.bind((host,port))
    client_socket.settimeout(1.0)
    if waiting == False or to>max_timeout:
        inp = input("Enter q to proceed or end to exit")
        if inp == "end":
            break
        message = "QUES"

    addr = ("10.8.39.109", 40000)

    start = time.time()
    client_socket.sendto(message.encode('utf-8'), addr)
    
        # sleep(2)
    try:
        data, server = client_socket.recvfrom(1024)
        end = time.time()
        elapsed = end - start
        print(data.decode('utf-8'))
        waiting = False    
        to=0 
        if answering == False:
            message = input("Enter answer")  
            answering = True 
    except socket.timeout:
        to+=1
        waiting = True
        if to>max_timeout:
            print("Server went out for max ", to, " timeouts")
        else:
            print('REQUEST TIMED OUT')