// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "../inc/stringTypeinfo.h"


// static TypeInfo *stringTI = NULL;


// memoryOperator stringGetSize() {
//     size_t size;

//     size = sizeof( char * );

//     return size;
// }


// unaryOperator stringDelete( elemPtr arg ) {
//     int res;

//     free( arg );

//     return res;
// }


// copyConstructor stringCopy( elemPtr destination, const elemPtr source ) {
//     int length = strlen( (char *) source ) + 1;

//     char *copy = malloc( length );
//     if ( copy == NULL ) {
//         return 1;
//     }

//     for ( unsigned i = 0; i < length; i++ ) {
//         *( ( char * ) copy + i ) = *( (char *) source + i );
//     }

//     return 0;
// }


// ComparisonResult stringCompare( const elemPtr elem1, const elemPtr elem2 ) {
//     int equalFlag = 1;
//     int len1 = strlen( (char *) elem1 );
//     int len2 = strlen( (char *) elem2 );
//     int minLength;

//     if ( len1 == len2 ) {

//         for ( unsigned index = 0; index < len1; index++ ) {

//             if ( *( (char *) elem1 + index ) != *( (char *) elem2 + index ) ) {
//                 equalFlag = 0;

//                 if ( (unsigned) *( (char *) elem1 + index ) < (unsigned) *( (char *) elem2 + index ) ) {
//                     return LESS;
//                 }
//                 else {
//                     return GREATER;
//                 }
//             }
//         }

//     } else { 
//         minLength = (len1 <= len2) ? len1 : len2;

//         for ( unsigned index = 0; index < minLength; index++ ) {

//             if ( *( (char *) elem1 + index ) != *( (char *) elem2 + index ) ) {

//                 if ( (unsigned) *( (char *) elem1 + index ) < (unsigned) *( (char *) elem2 + index ) ) {
//                     return LESS;
//                 }
//                 else {
//                     return GREATER;
//                 }

//             }
//         }
//     }

//     if ( equalFlag == 1 ) { return EQUAL ;}
//     if ( minLength == len1 ) { return LESS; }
//     return GREATER;
// }


// void stringPrint( const elemPtr output ) {
//     printf( "%s\n", ( char *) output );
// }


// const TypeInfo *getStringTI() {
//     if ( stringTI == NULL ) {
//         //stringTI->input = stringInput;
        
//         stringTI->compare = stringCompare;

//         stringTI->getSize = stringGetSize;
//         stringTI->destruct = stringDelete;

//         stringTI->print = stringPrint;
//     }
//     return stringTI;    
// }