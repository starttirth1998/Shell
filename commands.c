#include "change_dir.h"
#include "exit_shell.h"
#include "echo_print.h"
#include "present_working_directory.h"
#include "pinfo.h"

int change_dir(char **args);
int exit_shell(char **args);
int echo_print(char **args);
int present_working_directory(char **args);
int pinfo(char **args);

char *simple_commands[] = {
  "cd",
  "exit",
  "echo",
  "pwd",
  "pinfo"
};

int (*simple_commands_func[])(char **) = {
  &change_dir,
  &exit_shell,
  &echo_print,
  &present_working_directory,
  &pinfo
};
