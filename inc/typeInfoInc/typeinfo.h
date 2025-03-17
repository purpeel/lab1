#ifndef H_TYPEINFO
#define H_TYPEINFO
#include "../util.h"


typedef struct _TypeInfo {
    binaryOperator addition;

    compareOperator comparison;

    memoryOperator getSize;
    memoryOperator memDisengagement;

    printOperator print;
} TypeInfo;


#endif