#include <stdio.h>
#include <stdlib.h>

int wrong_rec(int n) {
	if (n == 2) {
		printf ("n == 2 --> %d == 2\n", n);
		return 1;
	} else {
				printf ("2 * wrong_rec(n/2) + n --> 2 * wrong_rec(%d/2) + %d\n", n, n);
				return (2 * wrong_rec(n/2) + n);
		};

}

int main(int argc, char *argv[])
{
	if (argc == 1) {
		printf("You must enter one parameter - integer.\n");
		return 1;
	}
	wrong_rec(atoi(argv[1]));

	return 0;
}
