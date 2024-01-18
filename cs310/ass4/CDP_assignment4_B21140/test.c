#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

struct double_integer{
    int a;
    int b;
};

void *thread_function(){
    // printf("dd\n");
    // int p_id = getpid();
    // int t_id = pthread_self();
    // printf("main function: PID = %d ThreadID = %d\n",p_id,t_id);
    // printf("entered child thread\n");
    // sleep(3);
    // printf("sleep ended\n");
    // return NULL;
    
    struct double_integer di;
    di.a=5;
    di.b=6;

    struct double_integer* ans = malloc(sizeof(struct double_integer));
    *ans = di;
    return (void*) ans;
}

int main(){
    // int p_id = getpid();
    // int t_id = pthread_self();
    // printf("thread function: PID = %d ThreadID = %d\n",p_id,t_id);
    pthread_t t1;
    // pthread_create(&t1, NULL,&thread_function,NULL);
    // sleep(5);
    // pthread_join(t1, NULL);

    struct double_integer* res;
    pthread_create(&t1, NULL,&thread_function,NULL);
    pthread_join(t1, (void**) &res);

    printf("%d\n", res->a);
    return 0;
}

