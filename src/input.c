#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/input.h"


const unsigned MAX_SIZE = 1024 * 1024;
const unsigned CHUNK_SIZE = 1024;


int receiver(char *buffer, int *length, FILE *stream) {
    buffer = malloc(CHUNK_SIZE);
    if (buffer == NULL)
        return 1;
    int c;
    unsigned index = 0, currentLength = 0;

    while (c != EOF) {
        c = getc(stream);
        *(buffer + index) = c;

        if (index >= MAX_SIZE) {
            free(buffer);
            return 2;
        }
        
        if (index > currentLength) {
            currentLength += CHUNK_SIZE;
            buffer = realloc(buffer, currentLength);
        }

        index++;
    }

    *length = index + 2; // +1 since the indices start with 0 and +1 to remember null-terminator char
    *(buffer + index + 1) = '\0';
    return 0;
}