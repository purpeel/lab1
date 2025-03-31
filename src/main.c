#include <stdio.h>
#include "../inc/main.h"


int main( const int argc, const char **argv ) {
    int isStopSignal = 0;
    while ( isStopSignal != -1 ) {
        isStopSignal = mainMenuCtrl( argc, argv );
    }
}