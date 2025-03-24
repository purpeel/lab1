#include <stdio.h>
#include <stdlib.h>
#include "../inc/collection.h"


int init( const char *source ) {
    Arr *array = malloc( sizeof( Arr * ) );



    array->capacity = 1;
    array->elemQuantity = 0;
    array->head = malloc( array->type.getSize() );
    array->tail = array->head;
    
    return 0;
}


int engagedMemoryControl( Arr *array ) {
    void *buffer;
    
    if ( array->elemQuantity > ( array->capacity / 2 ) && array->capacity < 1000 ) {
        buffer = realloc( array->head, array->capacity * array->type.getSize() * 2 );
        if ( buffer == NULL ) {
            return 9;
        } else {
            array->head = buffer;
            array->capacity *= 2;
            ( char * ) array->tail = ( char * ) array->head + ( array->capacity * array->type.getSize() / sizeof( char * ));
            array->tail = ( void * ) array->tail;
        }
    } else {
        buffer = realloc( array->head, (array->capacity + 100) * array->type.getSize()  );
        if ( buffer == NULL ) {
            return 9;
        } else {
            array->head = buffer;
            array->capacity *= 2;
            ( char * ) array->tail = ( char * ) array->head + ( array->capacity * array->type.getSize() );
            array->tail = ( void * ) array->tail;
        }
    }
    return 0;
}


int append( Arr *array, const char *element ) {
    
}