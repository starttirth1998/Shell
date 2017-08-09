#include "header.h"

int echo_print(char **args)
{
  int i=1;
  while(1)
  {
    if(args[i] == NULL)
    {
      fprintf(stdout, "\n");
      break;
    }
    else
    {
      fprintf(stdout, "%s ",args[i]);
      i++;
    }
  }
  return 1;
}
