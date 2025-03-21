#ifndef H_UTILITIES
#define H_UTILITIES
#include <string.h>
#include "collection.h"


const char *EXEC_MESSAGES[] = {"error 1", "error 2"};


typedef ResInfo ( *binaryOperator ) ( const void *, const void *, binaryOperator );
typedef ComparisonResult ( *compareOperator ) ( const void *, const void *, compareOperator );
typedef ResInfo ( *unaryOperator ) ( void *, unaryOperator );
typedef SizeResInfo ( *memoryOperator ) ( void *);
typedef void ( *printOperator ) ( const void *);


typedef struct _resInfo {
    int execCode;
    void *data;
} ResInfo;


typedef struct _sizeResInfo {
    int execCode;
    size_t size;
} SizeResInfo;


typedef enum _comparisonResult {
    GREATER = -1,
    EQUAL = 0,
    LESS = 1
} ComparisonResult;


void errorPrint( ResInfo );
void resultSet( ResInfo *, void *, int );
ResInfo charToDouble( const char * );
//dont like them down below
static ResInfo Copy( const char * );
ResInfo voidPtrRecorder( void *, const char * );
// hate them up there
#endif