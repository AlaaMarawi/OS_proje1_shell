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

char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}

int main(int argc, char *argv[],char ** envp)
{  
  int ex;
  int f; 
  int i;
  char *myargv [4];
  printf("** SHELL \n" );
  printf("Ana program:getpid: %d  getpppid: %d\n", getpid(), getppid());

//_________________________ 

  char *komut;
  char *komutlar[20];
  int j;

  char line[90]="    rakam 5 & dd 2 3 & mul 8 8";

  const char delim[2] = " "; 
  char *token;

  while(1){

    printf("myshell>> " );
    gets(line);  
  //gets(str);
  //scanf("%[^\n]s", &str);
  //if (scanf("%[^\n]s", &str) <= 0) exit(0);
  // printf("%s\n", str);

    strcpy(line,trimwhitespace(line));
  //printf("Komut satırı (trimmed): %s\n",line);

    komut= strtok(line, "&"); 
       if (komut==NULL){printf("BOŞ KOMUT\n"); continue;}
    strcpy(komut,trimwhitespace(komut));
    komutlar[0]=komut;
    j = 1;
    while (komut != NULL ){
     komut= strtok(NULL, "&");
     if(komut!= NULL)
       strcpy(komut,trimwhitespace(komut));
     komutlar[j]=komut;
     j++;

    }


    j=0;
    while (komutlar[j]!= NULL){ // komut var olduğu sürece
      printf("%d. komut: %s\n",j,komutlar[j]);

      token = strtok(komutlar[j], delim);
      char *prog= token;
      // >> div 4 2 ::::::
      if(strcmp(token,"div")==0 || strcmp(token,"mul")==0 ){

        //    while( token != NULL ) {
        //printf( "%s\n", token );
        token = strtok(NULL, delim);
        myargv [0]=token;
        token = strtok(NULL, delim);
        myargv [1]=token;
        myargv [2]=NULL;

        f= fork();
        if(f==0)
        {
          printf("Ana program: Exec calisti\n");
          ex = execve(prog,  &myargv, envp);
          perror("exec2: execve failed\n");
        }else{
          printf("%s programı bekleniyor... \n",prog);
          wait (&ex);
          printf("Ana programa Donus oldu \n");
        }


      }else if (strcmp(token,"rakam")==0){   // >> rakam 9  ::::::

       token = strtok(NULL, delim);
       myargv [0]=token;
       myargv [1]=NULL;

       f= fork();
       if(f==0)
       {
        printf("Ana program: Exec calisti\n");
        ex = execve(prog,  &myargv, envp);
        perror("exec2: execve failed\n");
        }else {
          printf("Ana program devam ediyor \n");
          sleep (1);
        }
      }else if(strcmp(token,"cat")==0){
        
          printf("cat: ");
          while(token!=NULL){
            token=strtok(NULL, " ");
            if(token==NULL){
                printf("\n");
            }else{
            printf("%s ",token);
            }
          }
      }else if(strcmp(token,"exit")==0){
        exit(0);
      }else if (strcmp(token,"clear")==0){
       system("clear");
      }else {
        printf("yanlis bir komut girdiniz \n");
      }
      j++;
  }
}

return 0;

}
