#ifndef VIEWS_H
#define VIEWS_H


#include "util.h"


typedef void View;


View mainMenuVw();
View errorVw( const int );
View endVw( const int );
View confirmKboardInputVw();
View doubleIsSetVw();
View stringIsSetVw();


#endif