#include <stdio.h>

int t, m, n;

int
main()
{
	int i;

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d %d", &m, &n);
		printf("Scenario #%d:\n", i + 1);
		printf("%d.", m * n);
		if (m % 2 && n % 2) printf("41\n\n");
		else printf("00\n\n");
	}

	return 0;
}
