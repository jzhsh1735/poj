#include <stdio.h>
#include <string.h>

int n;
int num[100];
char str[100][100];

int
main()
{
	int i, j;

	while (scanf("%d", &n), n)
	{
		getchar();

		int min = -1;
		for (i = 0; i < n; i++)
		{
			gets(str[i]);

			num[i] = 0;
			for (j = 0; j < strlen(str[i]); j++)
			{
				if (str[i][j] == ' ') num[i]++;
			}

			if (min < 0 || min > num[i]) min = num[i];
		}

		int ans = 0;
		for (i = 0; i < n; i++) ans += num[i] - min;

		printf("%d\n", ans);
	}

	return 0;
}
