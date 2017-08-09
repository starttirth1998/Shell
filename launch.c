#include<sys/wait.h>
#include "sig.h"
#include "background.h"
#include "header.h"

int launch(char **args)
{
  pid_t pid,wait_pid;
  int back,status;
  signal(SIGCHLD, handler);
  pid = fork();
  back = background(args);

  if(pid == 0)
  {
    if(execvp(args[0],args) == -1)
      fprintf(stderr,"Error: No Such Command Found\n");
    exit(0);
  }
  else if(pid < 0)
  {
    fprintf(stderr,"Error Creating Child Process\n");
  }
  else
  {
    if(!back)
    {
      do {
        wait_pid = waitpid(pid,&status,WUNTRACED);
      } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    else
    {
      printf("%d\n",(int)pid);
      //signal(SIGCHLD, handler);
    }
  }
  return 1;
}
