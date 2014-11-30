#include <stdio.h>

int t, n;

int
main()
{
	int temp, sum;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		sum = 1 - n;
		while (n--)
		{
			scanf("%d", &temp);
			sum += temp;
		}

		printf("%d\n", sum);
	}

	return 0;
}
