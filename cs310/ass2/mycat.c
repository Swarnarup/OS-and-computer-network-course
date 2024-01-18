#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

// int main(){
//     int f;
//     char buff[80];
//     char msg[50]=" hello world";
    
//     f=open("hello.txt",O_RDWR);
//     printf("f = %d",f);
//     if(f!=-1){
//         // printf("\nOpening\n");
//         // write(f , msg , sizeof(msg));
//         // lseek(f , 0, SEEK_SET);
//         read(f, buff, sizeof(msg));
//         printf("\n %s", buff);
        
//     }

//     close(f);
//     return 0;
// }


/////////////////////////////////////             ENTER ATMOST 2 FILES BY FILENAMES WITH EXTENSION AND OUTPUTS AS BOTH CONCATINATING BOTH THE FILES   
int main(){

    char str[20];
    gets(str);
    char str2[20];
    gets(str2);
    FILE* f = fopen(str,"r");

    if(f!=NULL){
        char c;
        while((c=fgetc(f)) != EOF ) putchar(c);
    }
    else{printf("\n");}

    fclose(f);
    printf("\n");
    FILE* f2 = fopen(str2,"r");

    if(f2!=NULL){
        char c;
        while((c=fgetc(f2)) != EOF ) putchar(c);
    }
    else{printf("\n");}

    fclose(f2);
    return 0;
}