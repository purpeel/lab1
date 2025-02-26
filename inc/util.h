#ifndef H_UTILITIES
    #define H_UTILITIES
    #include "typeInfoInc/typeinfo.h"


    const char *EXEC_MESSAGES[] = {"error 1", "error 2"};
    const arrElem DUMMY_ELEMENT = { NULL, "dummy" };


    typedef struct _arrElem {
        void *value;
        char *typeName;
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
        arrElem data;
    } resInfo;


    void errorPrint( resInfo );
    void resultSet( resInfo *, arrElem, int );

#endif