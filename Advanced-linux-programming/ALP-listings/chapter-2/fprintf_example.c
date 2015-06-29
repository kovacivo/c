#include <stdio.h>

int main(void)
{
	printf("This little program demonstrates features of I/O fprintf function - fprintf should NOT be buffered.\nThat's why its output will \
		show up after 1 second as it should.\n");

	while(1)
	{
		fprintf(stderr,".");
		sleep(1);
	}

	printf("\nEnd of program.\n");

	return 0;
}
