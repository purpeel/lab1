#ifndef H_UTILITIES
#define H_UTILITIES
#include "typeinfo.h"


const char *execMessages[] = {"error 1", "error 2"};


typedef struct _arrElem {
    void *value;
    typeInfo type;
} arrElem;


typedef struct _dynamicArray {
    int length;
    int size;
    arrElem *value;
} arr;


typedef struct _resInfo {
    int execCode;
    char *execMessage;
    arrElem result;
} resInfo;


void errorPrint(resInfo);
void resultSet(resInfo *, int);


#endif