#include "commands.h"
#include "launch.h"
#include<string.h>
#include "header.h"

int execute(char **args)
{
  int i,j;
  if(args[0] == NULL)
    return 1;

  j=0;
  while(simple_commands[j] != NULL)
  {
    j++;
  }
  for(i=0;i<j;i++)
  {
    if(strcmp(args[0],simple_commands[i]) == 0)
    {
      return (*simple_commands_func[i])(args);
    }
  }
  return launch(args);
}
