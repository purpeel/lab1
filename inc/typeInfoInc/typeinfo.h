#ifndef H_TYPEINFO
    #define H_TYPEINFO


    typedef struct _typeInfo {
        char *typeName;
        void ( *addOperator )( void *elem1, void *elem2 );
        void ( *multiplyOperator ) ( void *elem1, void *elem2 );
        char ( *compareOperator )( void *elem1, void *elem2 );
        void ( *initOperator ) ( void *element );
        void ( *printOperator ) ( void *value );
    } typeInfo;


#endif