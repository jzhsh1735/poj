#include <stdio.h>
#include <string.h>

int n;
char str[2][200];

int
main()
{
	int i, j, k, l;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%s %s", str[0], str[1]);

		i = 0;
		for (j = 0; j < strlen(str[0]) && i < strlen(str[1]); j++)
		{
			if (str[0][j] == str[1][i]) i++;
		}
		k = 0;
		for (l = strlen(str[0]) - 1; l >= 0 && k < strlen(str[1]); l--)
		{
			if (str[0][l] == str[1][k]) k++;
		}
		if (i == strlen(str[1]) || k == strlen(str[1])) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
