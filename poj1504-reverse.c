#include <stdio.h>

int n, a, b;

int
reverse(int v)
{
	int result = 0;

	while (v)
	{
		result = result * 10 + v % 10;
		v /= 10;
	}

	return result;
}

int
main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", reverse(reverse(a) + reverse(b)));
	}

	return 0;
}
