#include <stdio.h>
#include <stdlib.h>
#include "../inc/util.h"


void errorPrint( ResInfo result ) {
    
}


void resultSet ( ResInfo *result, void *passedValue, int callCode ) {
    result->execCode = callCode;
    result->data = (callCode == 0 ? passedValue : NULL);
}