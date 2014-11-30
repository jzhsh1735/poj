#include <stdio.h>
#include <string.h>

char str[500];

int
main()
{
	int i;

	while (gets(str), strcmp(str, "#") != 0)
	{
		int ans = 0;
		for (i = 0; i < strlen(str); i++)
		{
			if (str[i] != ' ') ans += (i + 1) * (str[i] - 'A' + 1);
		}

		printf("%d\n", ans);
	}

	return 0;
}
