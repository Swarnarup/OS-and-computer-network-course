# import random
# import socket

# server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# server_socket.bind(('', 12000))

# while True:
#     rand = random.randint(0, 10)
#     message, address = server_socket.recvfrom(1024)
#     message1 = b"1 * 2"
#     if rand >= 4:
#         server_socket.sendto(message1, address)



import socket
import threading as th
import random

# Generate question and answer
def gen_ques():
    x= random.randint(1,10)
    y= random.randint(1,10)
    l= ["+", "-", "*", "/"]
    eq= random.choice(l)
    eq= f"{x}{eq}{y}"
    ans= int(eval(eq))
    return eq, ans


def thread_fn(data, addr):
    score=0
    data = data.decode('utf-8')
    if(data=="QUES"):
        while True:
            (equation, answer)= gen_ques()
            # print("Sending: " + equation)
            s.sendto(equation.encode('utf-8'), addr)
            data, addr = s.recvfrom(1024)
            data = data.decode('utf-8')
            print("From connected user: " + data + "\nExpected: "+str(answer))
            print(addr)
            if( str(data) == str(answer)):
                score+=1
            else:
                score-=1
            data=f"Your score {score} \n[c] for coninue and [q] for quit "
            s.sendto(data.encode('utf-8'), addr)
            data, addr = s.recvfrom(1024)
            data = data.decode('utf-8')
            if(data=='c'):
                continue
            if(data=='q'):
                s.close()
                break

if __name__=='__main__':
   
    host = '10.8.30.211' #Server ip
    port = 4000

    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.bind((host, port))

    # print("Server Started")

    threads_list = {}

    while 1:
        data, addr = s.recvfrom(1024)
        if addr not in threads_list:
            thread = th.Thread( target= thread_fn, args=(data, addr))
            threads_list[addr] = thread
            thread.start()
        
        
        # thread.join()
        # thread2 = th.Thread( target= thread_fn, args=(data, addr))

        # thread2.start()

        # thread2.join()
    # threading.Thread(target=add1, args=(a,))
    
    for tt in threads_list:
        threads_list[tt].join()