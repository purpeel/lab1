#ifndef H_TYPEINFO
#define H_TYPEINFO
#include "../util.h"

typedef struct _TypeInfo {// lacks an input operator

    binaryOperator add; // optional
    // ??unaryOperator?? assign;
    // ?? ??unaryOperator?? copyConstruct;??
    // unaryOps that transform the object itself and the ones that create a copy should be differed

    compareOperator compare;

    memoryOperator getSize;
    unaryOperator destruct; //rename to free or destruct

    printOperator print;
} TypeInfo;


#endif