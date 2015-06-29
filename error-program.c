#include <stdio.h>


int * foo () {
int var = 3;
return & var ;
}
 /* At this point the stack region will be unwound */
/* The address of var is no longer valid ! */

void main () {
int * a;
a = foo () ;
printf (" % d " , * a ) ; /* This will produce erratic results
*/
}

