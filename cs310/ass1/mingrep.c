// #include<stdio.h>
// #include<dirent.h>
// #include<string.h>
// int main() {
//     char fn[10], pat[10], temp[200];
//     FILE *fp;
//  //   printf("\n Enter file name : ");
//     scanf("%s", pat);
//    // printf("Enter the pattern: ");
//     scanf("%s", fn);
//     fp = fopen(fn, "r");
//     while (!feof(fp)) {
//         fgets(temp, sizeof(fp), fp);
//         if (strcmp(temp, pat))
//             printf("%s", temp);
//     }
//     fclose(fp);
//     return 1;
// }




// int main() {
//     char pattern[MAX_LINE_LENGTH];
//     printf("Enter the pattern: ");
//     fgets(pattern, sizeof(pattern), stdin);
//     pattern[strcspn(pattern, "\n")] = '\0'; // Remove the newline character
    
//     char filename[MAX_LINE_LENGTH];
//     printf("Enter the filename: ");
//     fgets(filename, sizeof(filename), stdin);
//     filename[strcspn(filename, "\n")] = '\0'; // Remove the newline character
    
//     FILE *file = fopen(filename, "r");
//     if (file == NULL) {
//         printf("Error opening the file.\n");
//         return 1;
//     }
    
//     char line[MAX_LINE_LENGTH];
//     while (fgets(line, sizeof(line), file)) {
//         if (strstr(line, pattern)) {
//             printf("%s", line);
//         }
//     }
    
//     fclose(file);
//     return 0;
// }



int main(){
    char fn[10], pat[10], temp[200];
    FILE *fp ;
    // pat = "fuck";
    scanf("%s", pat);
    scanf("%s", fn);
    fp = fopen(fn, "r");
    while (fgets(temp, sizeof(temp), fp)) {

        // printf("%s",temp);
        
        if (strstr(temp, pat))
            printf("%s", temp);
    }
    return(0);

}