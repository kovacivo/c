#include <stdio.h>

int * foo () {
int var = 3;
int * tmp = ( int *) malloc ( sizeof ( int ) ) ;
* tmp = var ;
return tmp ;
}

void main () {
int * a;
a = foo () ;
printf (" % d " , * a ) ;
}