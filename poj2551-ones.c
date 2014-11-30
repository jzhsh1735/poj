#include <stdio.h>

int n;

int
main()
{
	int i, j;

	while (scanf("%d", &n) != EOF)
	{
		i = j = 1;
		while (i % n != 0)
		{
			j++;
			i = (10 * i + 1) % n;
		}
		printf("%d\n", j);
	}

	return 0;
}
