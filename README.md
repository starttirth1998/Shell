
---Features---
-> Modular Code
-> Make File
-> username@hostname prompt(Also fetched distibution name but not printed)
-> background with &
-> echo, echo alone
-> cd, cd &, cd ~, cd alone all are implemented
-> Changes are reflected in prompt
-> exit
-> pinfo
-> pwd
-> ; separated commands
-> signal for background exited

---Files---
-> shell.c : main file
-> read_line.c : File for reading command and separating ; separated commands
-> parser.c : To cut into arguments and pass for execution. args[0] coantains command.
-> execute.c : For execution of command.
  -> launch.c : For forking making child process. So that it won't exit
  -> commands.c : Contains all commands
-> header : Contains all header file
-> background.c : Check if & is present in command.
-> sig.c : Checks if background is exited

--- Compile AND Run ---
-> make all
-> ./shell
