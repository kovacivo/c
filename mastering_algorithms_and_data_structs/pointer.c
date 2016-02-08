#include <stdio.h>

int f(int **iptr) {
int a = 10;
*iptr = &a;
return 0;
}

int main()
{

	int x = 50;
	int *y = &x;
	int **yy = &y;
	int z = f(yy);


	int *iptr = 10;
	*iptr = 11;

	return 0;
}
