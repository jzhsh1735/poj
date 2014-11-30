#include <stdio.h>

int n;
int perm[100000];

int
main()
{
	int i;

	while (scanf("%d", &n), n)
	{
		for (i = 0; i < n; i++) scanf("%d", &perm[i]);
		for (i = 0; i < n; i++)
		{
			if (perm[perm[i] - 1] != i + 1) break;
		}
		if (i == n) printf("ambiguous\n");
		else printf("not ambiguous\n");
	}

	return 0;
}
