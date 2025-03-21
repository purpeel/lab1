#include <stdio.h>
#include <stdlib.h>
#include "../inc/collection.h"


ResInfo init( const char *source ) {
    ResInfo res;
    Arr *array = malloc( sizeof( Arr * ) );

    res = splitAndFill( array, source, " " );

    if ( ( TypeEnum * ) res.data == STRING ) {
        array->type = *getStringTI();
    } else if ( ( TypeEnum * ) res.data == DOUBLE ) {
        array->type = *getDoubleTI();
    } else {
        resultSet( &res, NULL, 6 );
        return res;
    }

    array->capacity = 0;
    array->elemQuantity = 0;
    array->head = malloc( array->type.getSize() );
    array->tail = array->head;
    
    resultSet( &res, ( void * ) array, 0 );
    return res;
}


ResInfo append( Arr *array, const void *element ) {
    if ( array->type == typeDeterminant())
}


