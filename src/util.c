#include <stdio.h>
#include <stdlib.h>
#include "../inc/util.h"


void errorPrint( resInfo result ) {
    
}


void resultSet ( resInfo *result, void *passedValue, int callCode ) {
    result->execCode = callCode;
    result->data = (callCode == 0 ? passedValue : NULL);
}