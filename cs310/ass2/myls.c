#include <stdio.h>
#include <string.h>
#include <dirent.h>

void flist(const char* dirname){
    DIR* dir = opendir(dirname);

    if (dir == NULL) return;

    struct dirent* entity;
    entity = readdir(dir);

    while(entity != NULL){
        printf("%s/%s\n", dirname, entity->d_name);

        if(entity->d_type == DT_DIR && strcmp(entity->d_name , ".")!=0 && strcmp(entity->d_name , "..")!=0){
            char path[100] = {0};
            strcat(path , dirname);
            strcat(path , "/");
            strcat(path , entity->d_name);
            flist(path);
        }
        entity = readdir(dir);
    }

    closedir(dir);
}

int main(int argc, char* argv[]){
    flist(".");
    return 0;
}
