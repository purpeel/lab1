#ifndef H_COLLECTION
#define H_COLLECTION
#include "typeInfoInc/typeinfo.h"
#include "util.h"


typedef struct _dynamicArray {
    int capacity;
    int elemQuantuty;
    void *head;
    void *tail;
    TypeInfo type;
} Arr;


ResInfo init( Arr * , const int, const char * );
ResInfo append( Arr *, void * );
ResInfo prepend( Arr *, void * );
ResInfo pop( Arr *, const int, void * );
ResInfo slice( Arr,  Arr *, const int, const int );
ResInfo delete( Arr * );
ResInfo map();
ResInfo where();
ResInfo extend( Arr *, const int );
ResInfo shrink( Arr * );
ResInfo getElem( Arr, const int );


#endif