#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"


const unsigned MAX_SIZE = 1024 * 1024;
const unsigned CHUNK_SIZE = 1024;

resInfo receiver(char *buffer, int *length, FILE *stream) {
    resInfo res;

    buffer = malloc(CHUNK_SIZE);
    // if (buffer == NULL)
    //     resultSet(&res, 1);
    //     return res;

    int c;
    unsigned index = 0, currentLength = 0;

    while (c != EOF) {
        c = getc(stream);
        *(buffer + index) = c;

        if (index >= MAX_SIZE) {
            free(buffer);
            // resultSet(&res, 2);
            // return res;
        }
        
        if (index > currentLength) {
            currentLength += CHUNK_SIZE;
            buffer = realloc(buffer, currentLength);
        }

        index++;
    }

    *length = index + 2; // +1 since the indices start with 0 and +1 to remember null-terminator char
    *(buffer + index + 1) = '\0';
    // resultSet(&res, 0);
    // return res;
}


resInfo typeDeterminant( arrElem *element, char *buffer ) {
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


void split( char *source, char *separator, int length, const int separatorLength ) {
    char *buffer, *sepBuffer;
    char c;

    int bufferLength = 0, prevIsSep = 0;
    int sourceLength = strlen( source );
    int separatorLength = strlen ( separator );

    for ( unsigned i = 0; i < length; i++ ) {
        c = *( source + i );
        if ( c == separator[0] && ( i + separatorLength < sourceLength )) {

            stringSlice( source, &sepBuffer, i, i + separatorLength );

            if ( stringComparator( sepBuffer, separator ) == 1 ) {

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


void stringSlice( char *source, char **slice, int beginning, int end ) {
    int sourceLen = strlen( source ) + 1;

    if ( end < beginning || beginning > sourceLen || end > sourceLen ) {
        return; //specify resultSet() script for insufficient slice indices
    }

    *slice = malloc( end - beginning + 1 );
    if ( *slice == NULL ) {
        return; //change the type of stringSlice() to resInfo and specify resultSet() script for unsuccessful memory allocation
    }

    for ( unsigned i = 0; i < ( end - beginning ); i++ ) {
        *( *slice + i ) = *( source + beginning + i );
    }

    *( *slice + end - beginning ) = '\0';
}


void stringCopy( char *destination, char *source ) {
    int length = strlen( source ) + 1;

    for ( unsigned i = 0; i < length; i++ ) {
        *( destination + i ) = *( source + i );
    }
}


int stringComparator( char *elem1, char *elem2 ) {
    int equalFlag = 1;
    int len1 = strlen( elem1 ) + 1;
    int len2 = strlen( elem2 ) + 1;

    if ( len1 == len2 ) {
        for ( unsigned index = 0; index < len1; index++ ) {
            if ( *( elem1 + index ) != *( elem2 + index ) ) {
                equalFlag = 0;
            }
        }
    } else { return 0; }

    return equalFlag;
}