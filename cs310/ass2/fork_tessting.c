#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
    // FILE* f = fopen("hello.txt","r");
    int id = fork();

    if(id!=0) printf("Parrant process : %d\n",id);
    else printf("child process : %d\n",id);

    if(f!=NULL){
        char c;
        while((c=fgetc(f)) != EOF ) putchar(c);
    }
    else{printf("file not found\n");}

    fclose(f);
    return 0;
}