
#include "read_line.h"
#include "parser.h"
#include "execute.h"
#define SIZE 1024
#include "header.h"

extern char *simple_commands[];
extern int (*simple_commands_func[])(char **);

int chdir(
	const char *path;
);

int execv(
	const char *path,
	char *const argv[]
);

int main(int argc,char **argv)
{
	int status;
	char hostname[SIZE],username[SIZE];
	char cwd[SIZE],dir[SIZE];
	char *line;
	char lin[SIZE];
	char **args;
	FILE *fp;

	/*Distribution Name*/
	char buffer[50],distribution_name[50];
	fp = popen("lsb_release -ds","r");
	fgets(buffer,50,fp);
	pclose(fp);
	int i=1;
	while(buffer[i] != ' ')
	{
		distribution_name[i-1] = buffer[i];
		i++;
	}

	getlogin_r(username,SIZE);
	gethostname(hostname,SIZE);
	getcwd(home,sizeof(home));
	do
	{
		getcwd(cwd,sizeof(cwd));
		if(strlen(cwd) < strlen(home))
		{
			printf("<%s@%s:%s>",username,hostname,cwd);
		}
		else
		{
			int i,j;
			getcwd(cwd,sizeof(cwd));
			i = strlen(home);
			dir[0] = '~';
			j = 1;
			while(cwd[i] != '\0')
			{
				dir[j] = cwd[i];
				i++;
				j++;
				//printf("%d %d %s",i,j,dir);
			}
			dir[j] = '\0';
			printf("<%s@%s:%s>",username,hostname,dir);
		}
		line = read_line();
		int i,j=0,len = strlen(line);
		for(i=0;i<len;i++)
		{
			lin[j++] = line[i];
			if(line[i] == ';' || i == len-1)
			{
				lin[j] = '\0';
				args = parse(lin);
				status = execute(args);
				j=0;
			}
		}
	}while(status);
	return 0;
}
