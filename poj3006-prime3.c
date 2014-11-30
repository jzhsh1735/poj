#include <stdio.h>

int a, d, n;

int
prime(int x)
{
	int i;

	if (x == 1) return 0;
	for (i = 2; i * i <= x; i++)
	{
		if (x % i == 0) return 0;
	}

	return 1;
}

int
main()
{
	//while (scanf("%d %d %d", &a, &d, &n), a && d && n)
	while (scanf("%d %d %d", &a, &d, &n) != EOF)
	{
		if (a == 0 && d == 0 && n == 0) break;

		int temp = 0;
		while (temp < n)
		{
			while (prime(a) == 0) a += d;
			temp++;
			if (temp == n) break;
			a += d;
		}

		printf("%d\n", a);
	}

	return 0;
}
