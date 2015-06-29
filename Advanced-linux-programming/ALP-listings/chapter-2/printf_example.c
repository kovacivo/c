#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("This little program demonstrates features of I/O printf function - printf should be buffered.\nThat's why its output will\
		not show up after 1 second as it should.\n");

	while(1)
	{
		printf(".");
		sleep(1);
	}

	fflush(stdout);
	printf("\nEnd of program.\n");

	return 0;
}
