#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int strtoint(char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
  if(('0'<=charnums[index]) && (charnums[index]<='9'))
  {

    if(!number)
      number= ( (int) charnums[index]) - 48;
    else
    {
      number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
  }
  else
  {
    number=-1;
    printf("\nGecersiz islem\n");
    break;
  }
}
return number;
}

int main(int argc, char *argv[])
{
 printf("** Rakam.c Programı \n");
 printf("Alt program:getpid: %d  getpppid: %d\n", getpid(), getppid());

 int grakam= strtoint(argv[0]);

 if (grakam== -1){
  printf("Girilen parametre rakam değildir\n"); return;
 }

switch (grakam){
 case  0 :
 printf("%d  >> sıfır \n",grakam); break;
 case  1 :
 printf("%d  >> bir \n",grakam); break;
 case  2 :
 printf("%d  >> iki \n",grakam); break;
 case  3 :
 printf("%d  >> üç \n",grakam); break;
 case  4 :
 printf("%d  >> dört \n",grakam); break;
 case  5 :
 printf("%d  >> beş \n",grakam); break;
 case  6 :
 printf("%d  >> altı \n",grakam); break;
 case  7 :
 printf("%d  >> yedi \n",grakam); break;
 case  8 :
 printf("%d  >> sekiz \n",grakam); break;
 case  9 :
 printf("%d  >> dokuz \n",grakam); break;
 default :
 printf("girilen rakam tek basamaklı değildir \n");
 break; 
}


return 0;
}

