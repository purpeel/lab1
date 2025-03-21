#include <stdio.h>
#include <stdlib.h>
#include "../inc/util.h"


void errorPrint( ResInfo result ) {
    
}


void resultSet ( ResInfo *result, void *passedValue, int callCode ) {
    result->execCode = callCode;
    result->data = (callCode == 0 ? passedValue : NULL);
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


ResInfo charToDouble( const char *source ) {
    ResInfo res;
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
            resultSet( &res, NULL, 5 );
            return res;
        }
    }
    resultSet( &res, ( void * ) buffer, 0 );
    return res;
}

// is this really necessary i dont even know
ResInfo voidPtrRecorder( const char *source ) {
    ResInfo res;

    TypeEnum type = *( TypeEnum * ) typeDeterminant( source ).data;

    void *placing;
    if ( type == DOUBLE ) {
        *( double * ) res.data = *( double * ) charToDouble( source ).data;
    } else if ( type == STRING ) {
        ( char * ) res.data = ( char * ) copy( source ).data;
    } else {
        resultSet( &res, NULL, 7 );
    }
    return( &res, res.data, )
}


static ResInfo copy( const char *source ) {
    ResInfo res;

    char *copy = malloc(  );
    if ( copy == NULL ) {
        resultSet(&res, NULL, 1);
        return res;
    }

    for ( unsigned i = 0; i < length; i++ ) {
        *( ( char * ) copy + i ) = *( (char *) source + i );
    }

    resultSet(&res, (void *) copy, 0);
    return res;
}
//until here