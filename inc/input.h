#ifndef H_INPUT
#define H_INPUT
#include "util.h"


typedef enum _typeEnum {
    DOUBLE = 1,
    STRING = 2
} TypeEnum;

int receiver(char *, int *, FILE *);

#endif