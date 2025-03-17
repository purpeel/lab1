#ifndef H_UTILITIES
#define H_UTILITIES
#include "typeInfoInc/typeinfo.h"
#include "collection.h"


const char *EXEC_MESSAGES[] = {"error 1", "error 2"};


typedef ResInfo ( *binaryOperator ) ( const void *arg1, const void *arg2, binaryOperator );
typedef ComparisonResult ( *compareOperator ) ( const void *arg1, const void *arg2, compareOperator);
typedef ResInfo ( *unaryOperator ) ( const void *arg );
typedef SizeResInfo ( *memoryOperator ) ( void * );
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

#endif