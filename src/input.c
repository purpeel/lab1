#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"


const unsigned MAX_SIZE = 1024 * 1024;
const unsigned CHUNK_SIZE = 1024;


ResInfo receiver(char *buffer, int *length, FILE *stream) {
    ResInfo res;

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


ResInfo typeDeterminant( const char *buffer ) {
    ResInfo res;
    TypeEnum type;

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
        type = DOUBLE;
    }
    else {
        type = STRING;
    }
    resultSet( &res, &type, 0 );
    return res;
} 


ResInfo splitAndFill( Arr *array, char *source, char *separator ) {
    ResInfo buffRes, res;
    TypeEnum buffType;
    char *buffer, *sepBuffer;
    char c;

    void *elem; 

    int bufferLength = 0, prevIsSep = 0, allowCompareType = 0;
    int sourceLength = strlen( source );
    int separatorLength = strlen ( separator );

    for ( unsigned i = 0; i < sourceLength; i++ ) {
        c = *( source + i );
        if ( c == separator[0] && ( i + separatorLength < sourceLength )) {

            stringSlice( source, &sepBuffer, i, i + separatorLength );

            if ( Comparison( sepBuffer, separator, Comparison ) == EQUAL ) {

                stringSlice( source, &buffer, i - bufferLength, i );
 
                if ( prevIsSep == 0 ) {
                    *( buffer + bufferLength ) = '\0';
                    buffRes = typeDeterminant( buffer );
                }

                if ( allowCompareType == 1 && buffType != *( TypeEnum * ) buffRes.data ) {
                    resultSet(&res, buffRes.data, 4);
                    return res;
                } else {
                    voidPtrRecorder( elem, buffer );
                    append( array, elem ); // most questionable yet and probably incorrect
                    array->type.typeName = *(TypeEnum *) buffRes.data;
                }

                prevIsSep = 1;
                bufferLength = 0;
                i += ( separatorLength - 1 );
                allowCompareType = 1;
                buffType = ( TypeEnum * ) buffRes.data;
                free( buffer );

            } else { 
                prevIsSep = 0;
                bufferLength++;
            }

            free( sepBuffer );

        } else if ( c == '\0' ) {

            stringSlice( source, &buffer, i - bufferLength, i );

            if ( prevIsSep == 0 ) {
                buffRes = typeDeterminant( buffer );
                free( buffer );
            }

            if ( allowCompareType == 1 && buffType != *( TypeEnum * ) buffRes.data ) {
                resultSet(&res, buffRes.data, 4);
                return res;
            } else {
                append( array, buffer );
                array->type.typeName = *(TypeEnum *) buffRes.data;
            }

            bufferLength = 0;

        } else { 
            bufferLength++;
            prevIsSep = 0;
        }
    }
    free( source );

    resultSet(&res, NULL, 0);
    return res;
}


static ComparisonResult Comparison( const void *elem1, const void *elem2 ) {
    int equalFlag = 1;
    int len1 = strlen( (char *) elem1 );
    int len2 = strlen( (char *) elem2 );
    int minLength;

    if ( len1 == len2 ) {

        for ( unsigned index = 0; index < len1; index++ ) {

            if ( *( (char *) elem1 + index ) != *( (char *) elem2 + index ) ) {
                equalFlag = 0;

                if ( (unsigned) *( (char *) elem1 + index ) < (unsigned) *( (char *) elem2 + index ) ) {
                    return LESS;
                }
                else {
                    return GREATER;
                }
            }
        }

    } else { 
        minLength = (len1 <= len2) ? len1 : len2;

        for ( unsigned index = 0; index < minLength; index++ ) {

            if ( *( (char *) elem1 + index ) != *( (char *) elem2 + index ) ) {

                if ( (unsigned) *( (char *) elem1 + index ) < (unsigned) *( (char *) elem2 + index ) ) {
                    return LESS;
                }
                else {
                    return GREATER;
                }

            }
        }
    }

    if ( equalFlag == 1 ) { return EQUAL ;}
    if ( minLength == len1 ) { return LESS; }
    return GREATER;
}