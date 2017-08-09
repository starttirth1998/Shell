#include "header.h"

int background(char **args)
{
  int len,i=0;
  while(args[i] != NULL)
  {
    i++;
  }
  len = strlen(args[i-1]);
  if(args[i-1][len-1] == '&')
  {
    if(len > 1)
      args[i-1][len-1] = '\0';
    else
      args[i-1] = NULL;
    return 1;
  }
  return 0;
}
