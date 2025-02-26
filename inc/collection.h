#ifndef H_COLLECTION
    #define H_COLLECTION
    #include "typeinfo.h"
    #include "util.h"


    typedef struct _arrElem {
        void *value;
        typeInfo type;
    } arrElem;


    typedef struct _dynamicArray {
        int length;
        int size;
        arrElem *value;
    } arr;


    resInfo append(arr *, arrElem);
    resInfo prepend(arr *, arrElem);
    resInfo pop(arr *, int, int *);
    resInfo slice(arr, arr *, int, int);
    resInfo delete(arr *);
    resInfo map();
    resInfo where();
    resInfo getElem(arr, int);


#endif