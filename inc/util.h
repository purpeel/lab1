#ifndef H_UTILITIES
#define H_UTILITIES


#include "stdbool.h"
#include "collection.h"


typedef enum _comparisonResult {
    GREATER = -1,
    EQUAL = 0,
    LESS = 1
} ComparisonResult;


typedef void *elemPtr;


// typedef int ( *binaryOperator )( const elemPtr, const elemPtr, elemPtr );
// typedef int ( *compareOperator )( const elemPtr, const elemPtr );
// typedef int ( *unaryOperator )( elemPtr );
// typedef int ( *copyConstructor )( elemPtr, const elemPtr );
// typedef size_t ( *memoryOperator )();
// typedef void ( *printOperator )( const elemPtr );
// typedef bool predicate( const elemPtr );


void errorPrint( int );
int charToInt( const char*, int * );


#endif