#include <stdio.h>
#include <math.h>

// program tries to find prime number

int main()
{
	int number = 0;
	printf("Put some number to tell if it's prime or not.\n");
	scanf("%d", &number);

	// divide the number starting with 2 up to square root to find out if the number is prime or not
	int square_root = (int)sqrt(number);
	printf("%d %d\n", number, square_root);
	int i = 2, tries = 0;

	// till square_root is less than i
	while (i <= square_root) {
		i++;
		tries++;
		printf("%d %d\n", i, square_root % i);

		// if it was divisible, then it was even number - so we must finish immediately
		if (square_root % i == 0) {
			printf("it was NOT prime.\n");
			return 0;
		}
	}

	printf("it was probably prime. The number of tests was %d\n", tries);

	return 0;
}
