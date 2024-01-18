#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>

int arr[10000000];

int no_threads;

pthread_barrier_t br;

struct thread_data{
   int* st;
   int sz;
};


int comparator(const void* p, const void* q) 
{ 
    return (*(int*)p - *(int*)q);
} 

void* thread_function(void* thread_arg){

    pthread_barrier_wait(&br);

    struct thread_data *my_data;
    my_data = (struct thread_data *) thread_arg;
    int* stt = my_data->st;
    int szz = my_data->sz;
    
    qsort(stt, szz, sizeof(int), comparator);
    return NULL;
}


int main(){

    scanf("%d", &no_threads);

    // struct thread_data thread_parameters[no_threads];

    for(int i=0;i<10000000;i++){
        arr[i] = rand()%1000;
    }

    pthread_t tid;

    int sort_start=0;

    int size_to_sort = 10000000/no_threads;

    pthread_t t_arr[no_threads];

    time_t now = time(NULL);
    
    pthread_barrier_init(&br, NULL, no_threads);
    for(int i=0;i<no_threads-1;i++){
        struct thread_data dt;
        dt.st = arr + i*size_to_sort;
        dt.sz = size_to_sort;
        sort_start+=size_to_sort;

        pthread_create(&t_arr[i],NULL,thread_function,&dt);
    }

    struct thread_data dt;
    dt.st = arr + size_to_sort*(no_threads-1);
    dt.sz = size_to_sort+1000%no_threads;

    pthread_create(&tid,NULL,thread_function,&dt);
    pthread_join(tid,NULL);

    for(int i=0;i<no_threads-1;i++){
        pthread_join(t_arr[i],NULL);
    }


    time_t end = time(NULL);
    pthread_barrier_destroy(&br);



    // sleep(10);

    // for(int i=0;i<1000;i++){
    //     printf("%d : %d\n",i,arr[i]);
    // }

    printf("time taken : %d\n",end-now);
    
    return 0;
}



// int cnt=0;
// void* thread_function(){
//     printf("thread ID , %d\n",pthread_self());
//     cnt++;
//     printf("cnt : %d\n",cnt);
//     return NULL;
// }

// int main(){
//     // int p_id = getpid();
//     // int t_id = pthread_self();
//     // printf("thread function: PID = %d ThreadID = %d\n",p_id,t_id);
    
//     pthread_t tt[10];
//     // pthread_create(&t, NULL, &thread_function, NULL);
//     // pthread_create(&t1, NULL,&thread_function,NULL);
//     // sleep(5);
//     // pthread_join(t1, NULL);
//     // sleep(1);
//     printf(" pid : %d\n",getpid());
    
//     for(int i=0;i<10;i++){
//         pthread_t t;
//         pthread_create(&t, NULL, &thread_function, NULL);
//         tt[i]=t;
//     }
       

//     for(int i=0;i<10;i++){
//          pthread_join(tt[i], NULL);
//     }

//     // pthread_create(&t, NULL, &thread_function, NULL);
//     printf("cnt : %d\n",cnt);


//     return 0;
// }

