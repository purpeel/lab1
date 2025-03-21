#ifndef H_STR_TYPEINFO
#define H_STR_TYPEINFO
#include "../util.h"
#include "typeinfo.h"


ResInfo stringSlice( const void *, void *, int, int );
ResInfo stringCopy( const void * ); 
ResInfo stringConcatenation( const void *, const void *, ResInfo );
unaryOperator stringDeletion( void *, ResInfo );
SizeResInfo stringGetSize ();
ComparisonResult stringComparison( const void *, const void *, ComparisonResult );
const TypeInfo *getStringTI();


#endif