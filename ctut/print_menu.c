#include <stdio.h>

char *menu[] =
{
	"  --------------------------------------------- ",
	" |                  ++ MENU ++                 |",
	" |                  ----------                 |",
	" |                                             |",
	" |             (0) Edit Preferences            |",
	" |                                             |",
	" |          Please enter choice below.         |",
	" |                                             |",
	"  --------------------------------------------- "
};

int main(void)
{
	int line_num;

	for (line_num = 0; line_num < 9; line_num++)
	   {
	      printf("%s\n",menu[line_num]);
	   }
	
	return 0;
}
