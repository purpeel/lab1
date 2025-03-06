#ifndef H_COLLECTION
    #define H_COLLECTION
    #include "typeinfo.h"
    #include "util.h"


    typedef struct _dynamicArray {
        int length;
        int size;
        void *value;
        TypeInfo type;
    } arr;


    resInfo append(arr *, void *);
    resInfo prepend(arr *, void *);
    resInfo pop(arr *, int, int *);
    resInfo slice(arr, arr *, int, int);
    resInfo delete(arr *);
    resInfo map();
    resInfo where();
    resInfo getElem(arr, int);


#endif