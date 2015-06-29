#include <stdio.h>

main()
{
int agg[5]; /* declares 5 ints */
int i = 0;
int sum = 0;
do /* loop to "fill" aggregate */
{
*(agg+i) = i*i;
i++;
} while(i<5);
i = 0;
do /* loop to add up values */
{
sum += *(agg+i);
i++;
} while(i<5);
printf("Sum = %d\n",sum);
}
