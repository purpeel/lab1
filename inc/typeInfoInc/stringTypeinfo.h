#ifndef H_STR_TYPEINFO
    #define H_STR_TYPEINFO
    #include "../util.h"
    #include "../collection.h"


    resInfo stringSlice( arrElem *, char **, int, int );
    resInfo stringCopy( arrElem *, char * ); 
    resInfo stringConcatenate( arrElem *, arrElem * );
    char stringCompare( char *, char * );


#endif