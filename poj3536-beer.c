#include <stdio.h>

int n;
int a, b, c;

int
main()
{
	int i, j;
	int min;

	scanf("%d", &n);
	min = -1;
	for (i = 1; i * i * i <= n; i++)
	{
		if (n % i != 0) continue;
		for (j = i; i * j * j <= n; j++)
		{
			if (n % (i * j) != 0) continue;
			if (min < 0 || i * j + n / i + n / j < min)
			{
				min = i * j + n / i + n / j;
				a = i;
				b = j;
				c = n / (i * j);
			}
		}
	}
	printf("%d %d %d\n", a, b, c);

	return 0;
}
