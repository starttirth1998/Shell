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

extern char *simple_commands[];
extern int (*simple_commands_func[])(char **);
