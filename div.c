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

int main(int argc, char **argv[])
{

 printf("** Div.c Programı\n");
 printf("Alt program:getpid: %d  getpppid: %d\n", getpid(), getppid());

 int p1= strtoint(argv[0]);
 int p2= strtoint(argv[1]);
 if(p1==-1 || p2==-1){
  printf("parametre hatası\n");
  return ;
}
double sonuc = (double)p1/(double)p2;

printf("p1, p2 :  %d , %d \n",p1,p2);
printf("p1 / p2: %f \n",sonuc);



return 0;
}

