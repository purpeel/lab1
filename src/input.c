#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"


const unsigned MAX_SIZE = 1024 * 1024;
const unsigned CHUNK_SIZE = 1024;

resInfo receiver(char *buffer, int *length, FILE *stream) {
    resInfo res;

    buffer = malloc(CHUNK_SIZE);
    if (buffer == NULL)
        resultSet(&res, NULL, 1);
        return res;

    int c;
    unsigned index = 0, currentLength = 0;

    while (c != EOF) {
        c = getc(stream);
        *(buffer + index) = c;

        if (index >= MAX_SIZE) {
            free(buffer);
            resultSet(&res, NULL, 2);
            return res;
        }
        
        if (index > currentLength) {
            currentLength += CHUNK_SIZE;
            buffer = realloc(buffer, currentLength);
        }

        index++;
    }

    *length = index + 2; // +1 since the indices start with 0 and +1 to remember null-terminator char
    *(buffer + index + 1) = '\0';
    resultSet(&res, NULL, 0);
    return res;
}


resInfo typeDeterminant( arr *array, char *buffer ) {
    unsigned asciiCode, isDoubleFlag = 1, pointCount = 0;

    int length = strlen( buffer );

    for ( unsigned buffIndex = 0; buffIndex < length; buffIndex++ ) {

        asciiCode = *(buffer + buffIndex);

        if ( asciiCode < '0' || asciiCode > '9' ) {

            if ( asciiCode != '.') {
                isDoubleFlag = 0;
            } else { 
                pointCount++;
            }

        }
    }

    if ( isDoubleFlag == 1 && pointCount <= 1 ) {
        //        
    }
    else {
        //
    }
} 


void split( char *source, char *separator ) {
    char *buffer, *sepBuffer;
    char c;

    int bufferLength = 0, prevIsSep = 0;
    int sourceLength = strlen( source );
    int separatorLength = strlen ( separator );

    for ( unsigned i = 0; i < sourceLength; i++ ) {
        c = *( source + i );
        if ( c == separator[0] && ( i + separatorLength < sourceLength )) {

            stringSlice( source, &sepBuffer, i, i + separatorLength );

            if ( stringComparison( sepBuffer, separator, stringComparison ) == EQUAL ) {

                stringSlice( source, &buffer, i - bufferLength, i );

                if ( prevIsSep == 0 ) {
                    *( buffer + bufferLength ) = '\0';
                    puts( buffer );
                }

                prevIsSep = 1;
                bufferLength = 0;
                i += ( separatorLength - 1 );
                free( buffer );

            } else { 
                prevIsSep = 0;
                bufferLength++;
            }

            free( sepBuffer );

        } else if ( c == '\0' ) {

            stringSlice( source, &buffer, i - bufferLength, i );

            if ( prevIsSep == 0 ) {
                puts( buffer );
                free( buffer );
            }

            bufferLength = 0;

        } else { 
            bufferLength++;
            prevIsSep = 0;
        }
    }
}