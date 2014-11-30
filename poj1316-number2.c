#include <stdio.h>

int flag[10000];

int
main()
{
	int i;

	for (i = 1; i < 10000; i++) flag[i] = 0;

	for (i = 1; i < 10000; i++)
	{
		int son = i, temp = i;
		while (temp > 0)
		{
			son += temp % 10;
			temp /= 10;
		}
		if (son < 10000) flag[son] = 1;
	}

	for (i = 1; i < 10000; i++)
	{
		if (flag[i] == 0) printf("%d\n", i);
	}

	return 0;
}
