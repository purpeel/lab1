#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/typeInfoInc/stringTypeInfo.h"


static TypeInfo *stringTI = NULL;


size_t stringGetSize() {
    size_t size;

    size = sizeof( char * );

    return size;
}


int stringDelete( void *arg ) {
    int res;

    free( arg );

    return res;
}


int stringCopy( const void *source ) {
    int length = strlen( (char *) source ) + 1;

    char *copy = malloc( length );
    if ( copy == NULL ) {
        return 1;
    }

    for ( unsigned i = 0; i < length; i++ ) {
        *( ( char * ) copy + i ) = *( (char *) source + i );
    }

    return 0;
}


int stringConcatenate( const void *elem1, const void *elem2 ) {
    int res;

    int len1 = strlen( (char *) elem1 );
    int len2 = strlen( (char *) elem2 );

    char *sum = malloc( len1 + len2 + 1);

    if ( sum == NULL ) {
        return 1;
    }

    for ( unsigned index = 0; index < len1 + len2; index++ ) {

        if ( index < len1 ) {
            *( sum + index ) = *( (char *) elem1 + index );
        }
        else {
            *( sum + index ) = *( (char *) elem2 + index - len1 );
        }
    }

    return 0;
}


ComparisonResult stringCompare( const void *elem1, const void *elem2 ) {
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


void stringPrint( const void *output ) {
    printf( "%s\n", ( char *) output );
}


const TypeInfo *getStringTI() {
    if ( stringTI == NULL ) {
        stringTI->add = stringConcatenate;
        stringTI->compare = stringCompare;

        stringTI->getSize = stringGetSize;
        stringTI->destruct = stringDelete;

        stringTI->print = stringPrint;
    }
    return stringTI;    
}