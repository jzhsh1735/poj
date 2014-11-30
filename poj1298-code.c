#include <stdio.h>
#include <string.h>

char code[] = "VWXYZABCDEFGHIJKLMNOPQRSTU";
char command[500], str[500];

int
main()
{
	int i;

	while (gets(command), strcmp(command, "ENDOFINPUT") != 0)
	{
		gets(str);
		gets(command);

		for (i = 0; i < strlen(str); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z') str[i] = code[str[i] - 'A'];
		}

		printf("%s\n", str);
	}

	return 0;
}
