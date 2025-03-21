#ifndef H_COLLECTION
#define H_COLLECTION
#include "typeInfoInc/stringTypeinfo.h"
#include "typeInfoInc/doubleTypeinfo.h"
#include "util.h"
#include "input.h"


typedef struct _dynamicArray {
    int capacity;
    int elemQuantity;
    void *head;
    void *tail;
    TypeInfo type;
} Arr;


ResInfo init( const char * );
ResInfo append( Arr *, const void * );
ResInfo prepend( Arr *, void * );
ResInfo pop( Arr *, const int, void * );
ResInfo slice( const Arr, const int, const int );
ResInfo delete( Arr * );
ResInfo map();
ResInfo where();
ResInfo extend( Arr *, const int );
ResInfo shrink( Arr * );
ResInfo getElem( Arr, const int );


#endif