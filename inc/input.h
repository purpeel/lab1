#ifndef H_INPUT
#define H_INPUT
#include "util.h"
#include "typeInfoInc/stringTypeinfo.h"


resInfo receiver(char *, int *, FILE *);
resInfo typeDeterminant( void *, char * );
void split( char *, char * );

#endif