#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "defs.h"
int FileCopy(char FileSource[], char FileDestination[])
{
    char    c[4096]; // or any other constant you like
    FILE    *stream_R = fopen(FileSource, "r");
    ifNULLEXIT(stream_R);
    FILE    *stream_W = fopen(FileDestination, "w");   //create and write to file
    ifNULLEXIT(stream_W);

    while (!feof(stream_R)) {
        size_t bytes = fread(c, 1, sizeof(c), stream_R);
        if (bytes) {
            fwrite(c, 1, bytes, stream_W);
        }
    }

    //close streams
    fclose(stream_R);
    fclose(stream_W);

    return 0;
}
