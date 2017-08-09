#define SIZE 1024
#define DELIMITER " ;\t\r\n\a"
#include "header.h"

char **parse(char *line)
{
	int size=SIZE,index=0;
	char **tokens = malloc(size*sizeof(char*));
	char *token;
	if(!tokens)
	{
		fprintf(stderr,"Error\n");
		exit(0);
	}
	token = strtok(line,DELIMITER);
	while(token != NULL)
	{
		tokens[index] = token;
		index++;
		if(index >= size)
		{
			size += SIZE;
			tokens = realloc(tokens,size*sizeof(char*));
			if(!tokens)
			{
				fprintf(stderr,"Error\n");
				exit(0);
			}
		}
		token = strtok(NULL,DELIMITER);
	}
	tokens[index] = NULL;
	return tokens;
}
