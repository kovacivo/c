#include <stdio.h>
#define PRINT(int)	printf("%d\n",int)

int main(void)
{
	int x,y,z;

	x=2; y=1; z=0;
	x = x && y || z; PRINT(x);
	PRINT(x || y && z);
	
	x=y=1;
	z = x++ - 1; PRINT(x); PRINT(z);
	z += -x++ + ++y; PRINT(x); PRINT(z);
	z = x / ++x; PRINT(z);

	return 0;
}
