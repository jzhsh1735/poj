#include <stdio.h>
#include <string.h>

char str[100];
int ans;

int
main()
{
	int i, j, k;

	while (scanf("%s", str), strcmp(str, "*") != 0)
	{
		ans = 0;
		for (i = 1; i < strlen(str) && ans == 0; i++)
		{
			for (j = 0; j + i < strlen(str) && ans == 0; j++)
			{
				for (k = j + 1; k + i < strlen(str) && ans == 0; k++)
				{
					if (str[j] == str[k] && str[j + i] == str[k + i]) ans = 1;
				}
			}
		}

		if (ans == 0) printf("%s is surprising.\n", str);
		else printf("%s is NOT surprising.\n", str);
	}

	return 0;
}
