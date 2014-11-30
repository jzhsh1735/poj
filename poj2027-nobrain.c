#include <stdio.h>

int n, x, y;

int
main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d", &x, &y);
		if (x < y) printf("NO BRAINS\n");
		else printf("MMM BRAINS\n");
	}

	return 0;
}
