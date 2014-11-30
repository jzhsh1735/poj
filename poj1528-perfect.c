#include <stdio.h>

int n;
int p[100000];

int
main()
{
	int i, j;

	for (i = 1; i <= 60000; i++) p[i] = 0;
	for (i = 1; i <= 60000; i++)
	{
		for (j = 2 * i; j <= 60000; j += i)
		{
			p[j] += i;
		}
	}

	printf("PERFECTION OUTPUT\n");
	while (scanf("%d", &n), n)
	{
		if (n / 10000) printf("%d", n);
		else if (n / 1000) printf(" %d", n);
		else if (n / 100) printf("  %d", n);
		else if (n / 10) printf("   %d", n);
		else printf("    %d", n);
		
		if (n > p[n]) printf("  DEFICIENT\n");
		else if (n == p[n]) printf("  PERFECT\n");
		else printf("  ABUNDANT\n");
	}
	printf("END OF OUTPUT\n");

	return 0;
}
