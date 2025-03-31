#include <stdio.h>
#include "../inc/view.h"


View mainMenuVw() {
    printf( "Choose one of the listed functions and enter a number of chosen function.\n" );
    printf( "Each function is followed by its number.\n\t\t-----\n" );
    printf( "1 - Enter array contents via keyboard and process them.\n" );
    printf( "2 - Provide array contents through reading from a .txt file.\n" );
    printf( "0 - Stop the execution.\n" );
}


View errorVw( const int exeCode ) {
    errorPrint( exeCode );
    printf( "Choose if you want program to continue its work - 1.\n");
    printf( "Or if you wish to abort the execution - 0.\n\t\t-----\n");
}


View endVw( const int context) {
    switch ( context )
    {
    case 0:

        printf( "Exexcution successfully finished.\n" );
        break;
    
    case 1:
        
        printf( "Execution terminated due to multiple cases of providing an incorrect value.\n" );
        break;

    }
}


View confirmKboardInputVw() {
    printf( "Confirm to procceed to keyboard input.\n\t\t-----\n" );
    printf( "1 - confirm and proceed to strings input. Can consist of symbols from standard 7 bit ASCII table.\n" );
    printf( "2 - confirm and proceed to input real numbers. Can be provided in decimal or exponential format.\n");
    printf( "0 - return to main menu.\n");
}


View doubleIsSetVw() {
    printf( "Contents type and operations set to double (real numbers).\n");
}


View stringIsSetVw() {
    printf( "Contents type and operations set to strings.\n");
}