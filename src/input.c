#include <stdio.h>
#include <stdlib.h>
#include "input.h"


const unsigned MAX_SIZE = 1024 * 1024;
const unsigned CHUNK_SIZE = 1024;

resInfo receiver(char *buffer, FILE *stream) {
    resInfo res;
    buffer = malloc(CHUNK_SIZE);
    if (buffer == NULL)
        resultSet(&res, 1);
        return res;
    int c;
    unsigned i = 0, length = 0;
    while (c != EOF) {
        c = getc(stream);
        *(buffer + i) = c;
        if (i >= MAX_SIZE) 
            free(buffer);
            resultSet(&res, 2);
            return res;
        if (i > length) 
            length += CHUNK_SIZE;
            buffer = realloc(buffer, length);
        i++;
    }
    *(buffer + i) = '\0';
    resultSet(&res, 0);
    return res;
}

resInfo typeDeterminant(arrElem element, char *buffer) {

} 