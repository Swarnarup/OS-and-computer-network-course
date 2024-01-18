/*
#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define ONEGB (1<<20)

using namespace std;

int main(){
  int p_id=getpid();
  printf("%d\n",p_id);
  int *blocks[10];
  int count=0;
  for(int i=0;i<100;i++){
    blocks[i]=(int*)malloc(ONEGB*sizeof(int));
    if(blocks[i]==NULL) {printf("refused after %d GB\n",count); break;}
    memset(blocks[i],1,sizeof(blocks[i]));  
    printf("got %d GB\n", count++);
  }
  

while(1);
return 0;
}

*/


//#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//#include<string.h>

//#define ONEGB (1<<20)

//using namespace std;
struct var{ int value; };

int main(int argc,char* argv[]){
  void* currentbreak = sbrk(0);
  printf("before allocation, break at %p\n",currentbreak);
  
  struct var *newvar = malloc(sizeof(struct var));
  newvar->value =10;
  
  currentbreak = sbrk(0);
  printf("after allocation, break at %p\n",currentbreak);
  
  free(newvar);
  
  currentbreak = sbrk(0);
  printf("after free, break at %p\n",currentbreak);
  return 0;
}
