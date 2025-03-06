#ifndef H_TYPEINFO
#define H_TYPEINFO

typedef resInfo ( *binaryOperator ) ( const void *arg1, const void *arg2, binaryOperator );
typedef comparisonResult ( *compareOperator ) ( const void *arg1, const void *arg2, compareOperator);
typedef resInfo ( *unaryOperator ) ( const void *arg );
typedef resInfo ( *memoryOperator ) ( void * );


typedef struct _TypeInfo {
    binaryOperator addition;
    binaryOperator multiplication;

    compareOperator comparison;

    memoryOperator memAllocation;
    memoryOperator memDisengagement;
    unaryOperator print;
} TypeInfo;


#endif