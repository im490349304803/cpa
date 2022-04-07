#include <stdio.h>
#include <dirent.h>
#define ifNULLEXIT(EXP) if((EXP) == NULL) exit(0)
#include "FileCopy.h"
main(void){
    struct dirent *de;
    DIR *dr = opendir(".");
    ifNULLEXIT(dr); 
    int num = 0;
    while ((de = readdir(dr)) != NULL) {
        char* source = de->d_name;
        if(source[0] != '_' || source [0] == '.')
            continue;
        char*copy = calloc(strlen(source)+ 4, 1);
        ifNULLEXIT(copy);
        strcat(copy, "_");
        strcat(copy, source);
        FileCopy(source, copy);
        free(copy);
    }
    closedir(dr);
}
