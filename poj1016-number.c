#include <stdio.h>
#include <string.h>

char buffer[20][1024];

int
inventory(char *from, char *to)
{
	int cnt[10], i;
	for (i = 0; i < 10; i++) cnt[i] = 0;

	for (i = 0; i < strlen(from); i++) cnt[from[i] - '0']++;
	to[0] = 0;
	for (i = 0; i < 10; i++)
	{
		if (cnt[i] > 0) sprintf(to + strlen(to), "%d%d", cnt[i], i);
	}

	return 0;
}

int
main()
{
	int i, j, flag;

	while (1)
	{
		scanf("%s", buffer[0]);
		if (strcmp(buffer[0], "-1") == 0) break;

		flag = 0;
		for (i = 1; i <= 15; i++)
		{
			inventory(buffer[i - 1], buffer[i]);
			for (j = 0; j < i; j++)
			{
				if (strcmp(buffer[i], buffer[j]) == 0) break;
			}

			if (i == 1 && j == 0)
			{
				printf("%s is self-inventorying\n", buffer[0]);
				flag = 1;
				break;
			}
			else if (i - 1 == j)
			{
				printf("%s is self-inventorying after %d steps\n", buffer[0], j);
				flag = 1;
				break;
			}
			else if (i > j)
			{
				printf("%s enters an inventory loop of length %d\n", buffer[0], i - j);
				flag = 1;
				break;
			}
		}
		if (flag == 0) printf("%s can not be classified after 15 iterations\n", buffer[0]);
	}

	return 0;
}
