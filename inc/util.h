#ifndef H_UTILITIES
#define H_UTILITIES
#include <stdbool.h>
#include <string.h>
#include "collection.h"


typedef enum _comparisonResult {
    GREATER = -1,
    EQUAL = 0,
    LESS = 1
} ComparisonResult;


typedef int ( *binaryOperator ) ( const elemPtr, const elemPtr, elemPtr );
typedef int ( *compareOperator ) ( const elemPtr, const elemPtr );
typedef int ( *unaryOperator ) ( elemPtr );
typedef size_t ( *memoryOperator ) ();
typedef void ( *printOperator ) ( const elemPtr );
typedef bool predicate( const elemPtr );

void errorPrint( int );
int charToDouble( const char * );


#endif