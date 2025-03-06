#ifndef H_STR_TYPEINFO
#define H_STR_TYPEINFO
#include "../util.h"
#include "../collection.h"
#include "typeinfo.h"


resInfo stringSlice( const void *, void *, int, int );
resInfo stringCopy( const void * ); 
resInfo stringConcatenation( const void *, const void *, resInfo );
resInfo stringDeletion ( void * );
resInfo stringAllocation ( void * );
comparisonResult stringComparison( const void *, const void *, comparisonResult );
const TypeInfo *getStringTI();


#endif