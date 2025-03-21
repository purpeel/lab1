#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/typeInfoInc/stringTypeInfo.h"


static TypeInfo *stringTI = NULL;


SizeResInfo stringGetSize() {
    SizeResInfo res;
    size_t size;

    size = sizeof( char * );

    res.size = size;
    res.execCode = 0;
    return res;
}


ResInfo stringDeletion( void *arg, ResInfo atomicDummy ) {
    SizeResInfo res;

    free( arg );

    res.execCode = 0;
    res.size = 0;
    return res;
}


ResInfo stringSlice( const void *source, void *slice, int beginning, int end ) {
    ResInfo res;

    int sourceLen = strlen( (char *) source ) + 1;

    if ( end < beginning || beginning > sourceLen || end > sourceLen ) {
        resultSet(&res, NULL, 3);
        return res;
    }

    slice = malloc( end - beginning + 1 );
    if ( slice == NULL ) {
        resultSet(&res, NULL, 1);
        return res;
    }

    for ( unsigned i = 0; i < ( end - beginning ); i++ ) {
        *( ( char * ) slice + i ) = *( (char *) source + beginning + i );
    }

    *( ( char * ) slice + end - beginning ) = '\0';
    
    resultSet(&res, slice, 0);
    return res;
}


ResInfo stringCopy( const void *source ) {
    ResInfo res;

    int length = strlen( (char *) source ) + 1;

    char *copy = malloc( length );
    if ( copy == NULL ) {
        resultSet(&res, NULL, 1);
        return res;
    }

    for ( unsigned i = 0; i < length; i++ ) {
        *( ( char * ) copy + i ) = *( (char *) source + i );
    }

    resultSet(&res, (void *) copy, 0);
    return res;
}


ResInfo stringConcatenation( const void *elem1, const void *elem2, ResInfo atomicDummy ) {
    ResInfo res;

    int len1 = strlen( (char *) elem1 );
    int len2 = strlen( (char *) elem2 );

    char *sum = malloc( len1 + len2 + 1);

    if ( sum == NULL ) {
        resultSet(&res, (void *) sum, 1);
        return res;
    }

    for ( unsigned index = 0; index < len1 + len2; index++ ) {

        if ( index < len1 ) {
            *( sum + index ) = *( (char *) elem1 + index );
        }
        else {
            *( sum + index ) = *( (char *) elem2 + index - len1 );
        }
    }

    resultSet(&res, (void *) sum, 0);
    return res;
}


ComparisonResult stringComparison( const void *elem1, const void *elem2, ComparisonResult atomicDummy ) {
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


const TypeInfo getStringTI() {
    if ( stringTI == NULL ) {
        stringTI->typeName = STRING;

        stringTI->addition = stringConcatenation;
        stringTI->comparison = stringComparison;

        stringTI->getSize = stringGetSize;
        stringTI->memDisengagement = stringDeletion;

        stringTI->print = stringPrint;
    }
}