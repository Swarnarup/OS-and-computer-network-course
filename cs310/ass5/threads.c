#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t lck;

int  cnt;

void thread_function( void* var ){

    pthread_mutex_lock( &lck );
    cnt++;
    int i=0;

    while(i<6){
        printf("Thread %d : at step %d count = %d\n",pthread_self() , i , cnt);
        // sleep(1);
        i++;
    }

    printf("Finished\n");

    pthread_mutex_unlock( &lck );
}

int main(){

    int err;

    pthread_t t1,t2;

    if(pthread_mutex_init( &lck, NULL) !=0){
        printf(" lock not created\n"); 
        exit(1);
    }
    else{printf("Lock created");}

    cnt=0;

    pthread_create(&t1,NULL,thread_function,NULL);
    pthread_create(&t1,NULL,thread_function,NULL);

    pthread_join(t1,NULL);
    pthread_join(t1,NULL);

    return 0;

}