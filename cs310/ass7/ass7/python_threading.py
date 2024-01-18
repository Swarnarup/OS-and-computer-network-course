import threading

def add1(num):
    for i in range(100000000):
        a[0]+=1
	# print("Cube: {}" .format(num * num * num))


def print_square(num):
	print("Square: {}" .format(num * num))



# if __name__ =="__main__":
a=[0]
threads=[]
for i in range(5):
    threads.append(threading.Thread(target=add1, args=(a,)))
    threads[-1].start()
    

for t in threads:                                                           
    print(type(t.join())) 
from time import sleep
# sleep(5)
print(a[0])
print("Done!")




# import threading                                                                

# def process(items, start, end):                                                 
#     for item in items[start:end]:                                               
#         try:                                                                    
#             api.my_operation(item)                                              
#         except Exception:                                                       
#             print('error with item')                                            


# def split_processing(items, num_splits=4):                                      
#     split_size = len(items) // num_splits                                       
#     threads = []                                                                
#     for i in range(num_splits):                                                 
#         # determine the indices of the list this thread will handle             
#         start = i * split_size                                                  
#         # special case on the last chunk to account for uneven splits           
#         end = None if i+1 == num_splits else (i+1) * split_size                 
#         # create the thread                                                     
#         threads.append(                                                         
#             threading.Thread(target=process, args=(items, start, end)))         
#         threads[-1].start() # start the thread we just created                  

#     # wait for all threads to finish                                            
#     for t in threads:                                                           
#         t.join()                                                                



# split_processing([1,2,3,4,5,6,7,8,9,10,11,12,13,14])