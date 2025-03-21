#ifndef H_TYPEINFO
#define H_TYPEINFO
#include "../util.h"

typedef struct _TypeInfo {
    TypeEnum typeName;

    binaryOperator addition;

    compareOperator comparison;

    memoryOperator getSize;
    unaryOperator memDisengagement;

    printOperator print;
} TypeInfo;


#endif