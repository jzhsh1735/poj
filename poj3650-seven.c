#include <stdio.h>
#include <string.h>

char buffer[100];

int
main()
{
	int i;

	while (gets(buffer), strcmp(buffer, "#") != 0)
	{
		for (i = 0; i < strlen(buffer); i++)
		{
			if (buffer[i] == ' ') printf("%%20");
			else if (buffer[i] == '!') printf("%%21");
			else if (buffer[i] == '$') printf("%%24");
			else if (buffer[i] == '%') printf("%%25");
			else if (buffer[i] == '(') printf("%%28");
			else if (buffer[i] == ')') printf("%%29");
			else if (buffer[i] == '*') printf("%%2a");
			else printf("%c", buffer[i]);
		}
		printf("\n");
	}

	return 0;
}
