#include <stdio.h>
int main ()
{
union {
unsigned short num;
unsigned char s[2];
} val;

/* 16 bit integer */
/* array of hex chars */

char *p = "0123456789abcdef";
printf("Input a number: ");
scanf("%hd", &val.num);
/* input as a short */
/* high byte */
putchar(p[val.s[1] >> 4]);
putchar(p[val.s[1] & 15]);
/* low byte */
putchar(p[val.s[0] >> 4]);
putchar(p[val.s[0] & 15]);
putchar('\n');

return 0;
}
