#define SIZE 1024
#include "header.h"

int pinfo(char **args)
{
  FILE *fd;
  char path[SIZE],buf[SIZE],buff[SIZE],pathexe[SIZE];
  if(args[1] == NULL)
  {
    fprintf(stderr,"Provide Process ID for information");
  }
  else
  {
    printf("pid -- %s\n",args[1]);
    strcpy(path,"/proc/");
    strcat(path,args[1]);
    strcpy(pathexe,path);
    strcat(pathexe,"/exe");
    strcat(path,"/status");
    fd = fopen(path,"r");
    while(fgets(buf,SIZE,fd) != NULL)
    {
      if((strstr(buf,"State")) != NULL)
      {
        int i;
        i=0;
        printf("Process Status -- ");
        while(buf[i] != ':')
        {
          i++;
        }
        i++;
        while(buf[i] != '\n')
        {
          printf("%c",buf[i]);
          i++;
        }
        printf("\n");
      }
      if((strstr(buf,"VmSize")) != NULL)
      {
        int i;
        i=0;
        printf("Memory -- ");
        while(buf[i] != ':')
        {
          i++;
        }
        i++;
        while(buf[i] != '\n')
        {
          printf("%c",buf[i]);
          i++;
        }
        printf("\n");
      }
    }
    fclose(fd);
    readlink(pathexe,buff,SIZE);
    printf("Executable Path -- %s\n",buff);
  }
  return 1;
}
