
#include<iostream>
#include<stdio.h>
#include<unistd.h>

using namespace std;

int main(){
int p_id=getpid();
printf("%d\n",p_id);
int n,lp;
scanf("%d",&n);
scanf("%d",&lp);

for(int i=0;i<lp;i++){
int* ptr = (int*)malloc(n * sizeof(int));
}
p_id=getpid();
printf("%d\n",p_id);

while(1);
return 0;
}
