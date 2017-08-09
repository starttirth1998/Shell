#include "header.h"

int present_working_directory(char **args)
{
  char cwd[1024];
  if(getcwd(cwd, sizeof(cwd)) != NULL)
    fprintf(stdout,"%s\n",getcwd(cwd,sizeof(cwd)));
  else
    fprintf(stderr,"getcwd() error\n");
  return 1;
}
