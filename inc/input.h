#ifndef H_INPUT
#define H_INPUT
#include "util.h"
#include "typeInfoInc/stringTypeinfo.h"


typedef enum _typeEnum {
    DOUBLE = 1,
    STRING = 2
} TypeEnum;

ResInfo receiver(char *, int *, FILE *);
ResInfo typeDeterminant( Arr *, char * );
static ComparisonResult Comparison( const void *, const void * );
ResInfo split( char *, char * );

#endif