#ifndef H_COLLECTION
#define H_COLLECTION
#include "typeinfo.h"
#include "util.h"


resInfo append(arr *, arrElem);
resInfo prepend(arr *, arrElem);
resInfo pop(arr *, int, int *);
resInfo slice(arr, arr *, int, int);
resInfo delete(arr *);
resInfo map();
resInfo where();


#endif