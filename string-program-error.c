#include <stdio.h>
#include <string.h>

int main()
{
   char istr[128];
   char *tstr;
   int i;
   int llen;
   while(1)
   {
      printf("Enter string ");
      fgets(istr,128,stdin);
      if((llen=strlen(istr))==0) break;
      tstr = malloc(char *, 128);
      printf("Dlzka zadaneho retazca bola: %d\n", llen);
      strncpy(tstr,istr,llen);
      i = 0;
      do
      {
         if(tstr[i]>='A' && tstr[i]<='Z')
            tstr[i] += 'a'-'A';
         else if(tstr[i]>='a' && tstr[i]<='z')
                 tstr[i] += 'A'-'a';
      } while(i++<=llen);
      printf(" Original string = %s\n",istr);
      printf("Transformed string = %s\n",tstr);
   }
   tstr='\0';
   return 0;
}
