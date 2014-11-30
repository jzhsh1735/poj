#include <stdio.h>

int n;
int p[1000000];

int
main()
{
	int i, j;

	for (i = 0; i < 1000000; i++) p[i] = 1;
	p[0] = p[1] = 0;
	for (i = 2; i < 1000000; i++)
	{
		if (p[i] == 1) for (j = i + i; j < 1000000; j += i) p[j] = 0;
	}

	while (scanf("%d", &n), n)
	{
		for (i = 2; i < n; i++)
		{
			if (p[i] && p[n - i])
			{
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
	}

	return 0;
}
