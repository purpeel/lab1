#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/typeInfoInc/stringTypeInfo.h"


resInfo stringSlice( arrElem *source, int beginning, int end ) {
    resInfo res;

    int sourceLen = strlen( (char *) source->value ) + 1;

    if ( end < beginning || beginning > sourceLen || end > sourceLen ) {
        resultSet(&res, DUMMY_ELEMENT.value, 3);
        return res;
    }

    char *slice = malloc( end - beginning + 1 );
    if ( *slice == NULL ) {
        resultSet(&res, DUMMY_ELEMENT.value, 1);
        return res;
    }

    for ( unsigned i = 0; i < ( end - beginning ); i++ ) {
        *( slice + i ) = *( (char *) source->value + beginning + i );
    }

    *( slice + end - beginning ) = '\0';
    
    resultSet(&res, (void *) slice, 0);
    return res;
}


resInfo stringCopy( arrElem *source ) {
    resInfo res;

    int length = strlen( (char *) source->value ) + 1;

    char *copy = malloc( length );
    if ( copy == NULL ) {
        resultSet(&res, DUMMY_ELEMENT.value, 1);
        return res;
    }

    for ( unsigned i = 0; i < length; i++ ) {
        *( copy + i ) = *( (char *) source->value + i );
    }

    resultSet(&res, (void *) copy, 0);
    return res;
}


resInfo stringConcatenate( arrElem *elem1, arrElem *elem2 ) {
    resInfo res;

    int len1 = strlen( (char *) elem1->value );
    int len2 = strlen( (char *) elem2->value );

    char *sum = malloc( len1 + len2 + 1);

    if ( sum == NULL ) {
        resultSet(&res, (void *) sum, 1);
        return res;
    }

    for ( unsigned index = 0; index < len1 + len2; index++ ) {

        if ( index < len1 ) {
            *( sum + index ) = *( (char *) elem1->value + index );
        }
        else {
            *( sum + index ) = *( (char *) elem2->value + index - len1 );
        }
    }

    resultSet(&res, (void *) sum, 0);
    return res;
}


char stringCompare( char *elem1, char *elem2 ) {
    int equalFlag = 1;
    int len1 = strlen( elem1 );
    int len2 = strlen( elem2 );
    int minLength;

    if ( len1 == len2 ) {

        for ( unsigned index = 0; index < len1; index++ ) {

            if ( *( elem1 + index ) != *( elem2 + index ) ) {
                equalFlag = 0;

                if ( (unsigned) *( elem1 + index ) < (unsigned) *( elem2 + index ) ) {
                    return '<';
                }
                else {
                    return '>';
                }
            }
        }

    } else { 
        minLength = (len1 <= len2) ? len1 : len2;

        for ( unsigned index = 0; index < minLength; index++ ) {

            if ( *( elem1 + index ) != *( elem2 + index ) ) {

                if ( (unsigned) *( elem1 + index ) < (unsigned) *( elem2 + index ) ) {
                    return '<';
                }
                else {
                    return '>';
                }

            }
        }
    }

    if ( equalFlag == 1 ) { return '=' ;}
    if ( minLength == len1 ) { return '<'; }
    return '>';
}