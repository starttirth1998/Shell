
#include "header.h"

int change_dir(char **args)
{
  char rel_path[SIZE];
  if(args[1] == NULL)
  {
    chdir(home);
  }
  else if(args[1][0] == '~')
  {
    int i,j;
    for(i=0;i<strlen(home);i++)
    {
      rel_path[i] = home[i];
    }
    j=1;
    while(args[1][j] != '\0')
    {
      rel_path[i] = args[1][j];
      i++;
      j++;
    }
    rel_path[i] = '\0';
    chdir(rel_path);
  }
  else
  {
    if(chdir(args[1]) != 0)
      fprintf(stderr,"No directory\n");
  }
  return 1;
}
