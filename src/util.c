#include <stdio.h>
#include <stdlib.h>
#include "../inc/util.h"


void errorPrint( resInfo result ) {
    
}


void resultSet ( resInfo *result, void *passedValue, int callCode ) {
    result->execCode = callCode;
    result->execMessage = EXEC_MESSAGES[callCode];
    result->data = (callCode == 0 ? passedValue : DUMMY_ELEMENT.value);
}