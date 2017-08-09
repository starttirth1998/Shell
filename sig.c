#include<signal.h>
#include<sys/wait.h>
#include "header.h"

void handler(int sig)
{
  int status;
  pid_t pid;
  pid = waitpid(-1,&status,WNOHANG);
  if(pid > 0)
  {
    if(WIFEXITED(status) == 0 || WIFSIGNALED(status) == 0)
    {
      printf("Pid %d exited normally.\n", pid);
    }
  }
}
