#include <stdio.h>
#include <stdlib.h>
#include "../inc/util.h"


void errorPrint( int result ) {
    
}


double pow( const double number, int power ) {
    double res = 1.0;
    if ( power == 0 ) { return res; } 
    while ( power != 0 ) {
        res *= number;
        power--;
    }
    return res;
}


int charToDouble( const char *source ) {
    double buffer = 0.0;

    int integerPartCount = 0;

    for ( short index = 0; *( source + index ) != '\0'; index++ ) {
        if ( *( source + index ) != '.' ) {
            integerPartCount++;
        } else if ( *( source + index ) == '.' ) {
            break;
        }
    }
    for  ( short index = 0; *( source + index ) != '\0'; index++, integerPartCount-- ) {
        if ( *( source + index ) == '.' ) {
            continue;
        } else if ( ( int ) *( source + index ) >= '0' || ( int ) *( source + index ) <= '9' ) {
            buffer += ( ( ( int ) *( source + index ) - '0' ) * pow( 10.0, integerPartCount ) );
        } else {
            return 5;
        }
    }
    return 0;
}