#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
char str[500];

int
main()
{
	int i, j;

	while (scanf("%d", &n), n)
	{
		scanf("%s", str);
		m = strlen(str) / n;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (j % 2 == 0) printf("%c", str[j * n + i]);
				else printf("%c", str[j * n + n - 1 - i]);
			}
		}
		printf("\n");
	}

	return 0;
}
