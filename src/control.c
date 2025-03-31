#include <stdio.h>
#include <stdlib.h>
#include "../inc/control.h"


Controller gatewayCtrl( int exeCode, int calledByItselfCount ) {

    system( "clear" );
    if ( calledByItselfCount == 2 ) { 

        endVw( 1 );
        exit( 1 );
    }

    if ( exeCode != 0 ) {
        int cmd = 0;
        char *input;
        errorVw( exeCode );
        gatewayCtrl( inputCmdMdl( &cmd, input, 1 ), ++calledByItselfCount );

        switch ( cmd )
        {
        case 0:

            endVw( 0 );
            return -1;

        case 1:

            return 1;
        
        default:

            break;

        }
    } 
    
    return 0;
}


// int isArgvCorrectCtrl( int argc, const char **argv ) {
//     if ( argc == 1 || containsFilename( argv ) == 0 ) {
//         return 11;
//     } else {
//         return 0;
//     }
// }


Controller kboardInputCtrl() {
    int cmd = 0;
    char *input;
    // Arr array;

    confirmKboardInputVw();
    printf( "%d\n" , gatewayCtrl( inputCmdMdl( &cmd, input, 2 ), 0 ) );
    // free( input );

    switch ( cmd )
    {
    case 0:

        break;
    
    case 1:

        stringIsSetVw();
        // getStringTI();
        // kboardInputMdl( &array );
        break;
        
    case 2:

        doubleIsSetVw();
        // getDoubleTI();
        // kboardInputMdl( &array );
        break;
        
    default:
        break;
    }
    return 0;
}



Controller mainMenuCtrl( const int argc, const char **argv ) {
    int cmd = 0;
    char *input;

    system( "clear" );
    mainMenuVw();
    if ( gatewayCtrl( inputCmdMdl( &cmd, input, 2 ), 0 ) == 1 ) {
        return 0;
    }
    free( input );
    
    switch ( cmd )
    {
    case 0:

        // endVw( 0 );
        return -1;

    case 1:

        gatewayCtrl( kboardInputCtrl(), 0 );
        break;

    case 2:

        // fileInputVw( argc );
        // gatewayCtrl( isArgvCorrectCtrl( argc, argv ) );
        // gatewayCtrl( fileInputCtrl( argc, argv ) );

        break;

    default:

        break;
    
    }
    
    return 0;
}