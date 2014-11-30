#include <stdio.h>
#include <string.h>

int forward_top;
int backward_top;
char forward[200][200];
char backward[200][200];

char command[200];
char current[200];

int
main()
{
	forward_top = backward_top = -1;
	strcpy(current, "http://www.acm.org/");
	while (scanf("%s", command), strcmp(command, "QUIT") != 0)
	{
		if (strcmp(command, "VISIT") == 0)
		{
			backward_top++;
			strcpy(backward[backward_top], current);
			forward_top = -1;
			scanf("%s", current);
			printf("%s\n", current);
		}
		else if (strcmp(command, "BACK") == 0)
		{
			if (backward_top < 0)
			{
				printf("Ignored\n");
				continue;
			}

			forward_top++;
			strcpy(forward[forward_top], current);
			strcpy(current, backward[backward_top]);
			backward_top--;
			printf("%s\n", current);
		}
		else if (strcmp(command, "FORWARD") == 0)
		{
			if (forward_top < 0)
			{
				printf("Ignored\n");
				continue;
			}

			backward_top++;
			strcpy(backward[backward_top], current);
			strcpy(current, forward[forward_top]);
			forward_top--;
			printf("%s\n", current);
		}
	}

	return 0;
}
