#ifndef H_UTILITIES
#define H_UTILITIES
#include "typeInfoInc/typeinfo.h"
#include "collection.h"


const char *EXEC_MESSAGES[] = {"error 1", "error 2"};


typedef struct _resInfo {
    int execCode;
    void *data;
} resInfo;


typedef enum {
    GREATER = -1,
    EQUAL = 0,
    LESS = 1
} comparisonResult;


void errorPrint( resInfo );
void resultSet( resInfo *, void *, int );

#endif