#include <stdio.h>
#include <string.h>

#define POLE {4,3,2,1}
void insertsort(int array[], int arrlen);

int main()
{
   int pole[] = POLE;

   printf("Array before...\n");
   int i=0;
   int len = sizeof(pole)/sizeof(pole[0]);
   printf("array length %d\n", len);
   for(i=0; i<len;i++)
      printf("%d ",pole[i]);
   printf("\n");


   insertsort(pole,len);
   printf("Array after...\n");
   for(i=0; i<len;i++)
      printf("%d ",pole[i]);
   printf("\n");

   return 0;
}

void insertsort(int array[], int arrlen)
{
   int i = 0, j = 0, key = 0;
   for(j = 1;j < arrlen; j++)
   {
      key = array[j];
      printf("key %d\n", key);
      // insert array[j] into sorted sequence array[1..j-1]
      i = j - 1;
      while ((i >= 0) && (array[i] > key))
      {
         array[i + 1] = array[i];
         i = i - 1;
      }
      array[i + 1] = key;
   }
}
