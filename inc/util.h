#ifndef H_UTILITIES
    #define H_UTILITIES
    #include "typeInfoInc/typeinfo.h"
    #include "collection.h"


    const char *EXEC_MESSAGES[] = {"error 1", "error 2"};
    const arrElem DUMMY_ELEMENT = { NULL };


    typedef struct _resInfo {
        int execCode;
        char *execMessage;
        void *data;
    } resInfo;


    void errorPrint( resInfo );
    void resultSet( resInfo *, void *, int );

#endif