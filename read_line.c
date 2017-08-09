#define SIZE 1024
#include "header.h"

char *read_line()
{
	char *buf;
	int c,size,index;
	size = SIZE;
	index = 0;
	buf = malloc(sizeof(char)*size);
	if(!buf)
	{
		fprintf(stderr,"Memory Not Allocated\n");
		exit(0);
	}
	while(1)
	{
		c = getchar();
		if(c == EOF || c == '\n')
		{
			buf[index] = '\0';
			return buf;
		}
		else
		{
			buf[index] = c;
		}
		index++;
		if(index >= size)
		{
			size = size + SIZE;
			buf = realloc(buf,size);
			if(!buf)
			{
				fprintf(stderr,"Memory Not Allocated\n");
				exit(0);
			}
		}
	}
}
