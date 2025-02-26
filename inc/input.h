#ifndef H_INPUT
    #define H_INPUT
    #include "util.h"


    resInfo receiver(char *, int *, FILE *);
    resInfo typeDeterminant( arrElem *, char * );
    void split( char *, char *, int, int );
    void stringSlice( char*, char **, int, int );
    void stringCopy( char *, char * ); // also ought to be relocated
    int stringComparator( char *, char * ); // should be replaced with comparator for strings from typeinfo 

#endif