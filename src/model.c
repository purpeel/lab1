#include <stdio.h>
#include <stdlib.h>
#include "../inc/model.h"


Model inputCmdMdl( int *cmd, char *input, const int context ) { // this model records an integer number of command from range of [1, context] into *cmd
    input = ( char * ) malloc( 9 );
    if ( input == NULL ) {
        return 3;
    }

    printf( ">> " );
    fgets( input, 9, stdin );
    fflush( stdin );
    
    int exeCode = charToInt( input, cmd );

    switch ( exeCode )
    {
    case 0:

        if ( *cmd > context ) { return 12 ;}
        else { return 0; }
    
    default:

        return exeCode;

    }
}


// Model kboardInputMdl( Arr *array ) {
    
// }