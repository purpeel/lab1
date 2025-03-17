#include <stdio.h>
#include <stdlib.h>
#include "../inc/typeInfoInc/doubleTypeInfo.h"


static TypeInfo *doubleTI = NULL;


ResInfo doubleCopy( void *source ) {
    ResInfo res;

    res.data = malloc( doubleGetSize( source ).size );
    if ( res.data == NULL ) {
        resultSet( &res, NULL, 1 );
        return res;
    }
    (double *) res.data = (double *) source;

    resultSet( &res, res.data, 0 );
    return res;
}


