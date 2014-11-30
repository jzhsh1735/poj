#include <stdio.h>

int t, n;

int
main()
{
	int i, j;

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for (j = 0; j * j <= n; j++);

		printf("%d\n", j - 1);
	}

	return 0;
}
