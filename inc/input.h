#ifndef H_INPUT
#define H_INPUT
#include "util.h"


typedef enum _typeEnum {
    DOUBLE = 1,
    STRING = 2
} TypeEnum;

ResInfo receiver(char *, int *, FILE *);
ResInfo typeDeterminant( const char * );
static ComparisonResult Comparison( const void *, const void * );
ResInfo splitAndFill( Arr *, char *, char * );

#endif