#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/util.h"


void errorPrint( int result ) {
    printf("hehe\n");
}


// double pow( const double number, int power ) {
//     double res = 1.0;
//     if ( power == 0 ) { return res; } 
//     while ( power != 0 ) {
//         res *= number;
//         power--;
//     }
//     return res;
// }


// int charToDouble( const char *source ) {
//     double buffer = 0.0;

//     int integerPartCount = 0;

//     for ( short index = 0; *( source + index ) != '\0'; index++ ) {
//         if ( *( source + index ) != '.' ) {
//             integerPartCount++;
//         } else if ( *( source + index ) == '.' ) {
//             break;
//         }
//     }
//     for  ( short index = 0; *( source + index ) != '\0'; index++, integerPartCount-- ) {
//         if ( *( source + index ) == '.' ) {
//             continue;
//         } else if ( ( int ) *( source + index ) >= '0' || ( int ) *( source + index ) <= '9' ) {
//             buffer += ( ( ( int ) *( source + index ) - '0' ) * pow( 10.0, integerPartCount ) );
//         } else {
//             return 5;
//         }
//     }
//     return 0;
// }


int power( const int base, const int power, int *value ) {
    int res = 1;

    if ( power > 0 ) {
        int powBuff = power;

        while ( powBuff > 0 ) {
            res *= base;
            powBuff--;
        }
    }
    
    *value = res;
    return 0;
}


int charToInt( const char *source, int *value ) {
    int len = 0;
    int buff;
    
    for ( short index = 0; *( source + index ) != '\0' || *( source + index ) != '\n'; index++ ) {
        int asciiCode = ( int ) *( source + index );
        
        if ( asciiCode == '\0' || asciiCode == '\n' ) { 
            break;
        } else {
            len++;
        }
    }

    if ( len == 0 ) {
        return 14;
    }

    for ( short index = 0; *( source + index ) != '\0' || *( source + index ) != '\n'; index++ ) {
        int asciiCode = ( int ) *( source + index );
        if ( asciiCode == '\0' || asciiCode == '\n' ) { 
            break;
        }

        if ( asciiCode < '0' || asciiCode > '9' ) {
            return 9;
        } else {
            buff = 0;
            power( 10, len - index - 1, &buff );
            *value += ( asciiCode - '0') * buff;
        }
    }

    return 0;
}