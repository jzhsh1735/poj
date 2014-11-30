#include <stdio.h>

int
prog(int val)
{
	int result = 1;
	while (val != 1)
	{
		if (val % 2 == 0) val /= 2;
		else val = 3 * val + 1;
		result++;
	}

	return result;
}

int
main()
{
	int i, j, k;

	while (scanf("%d %d", &i, &j) != EOF)
	{
		int max = -1;
		for (k = (i > j? j:i); k <= (i > j? i:j); k++)
		{
			int len = prog(k);
			if (max < 0 || len > max) max = len;
		}
		printf("%d %d %d\n", i, j, max);
	}

	return 0;
}
