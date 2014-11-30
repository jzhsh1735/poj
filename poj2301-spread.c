#include <stdio.h>

int n, x, y;

int
main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d", &x, &y);
		if (x < y || (x - y) % 2 == 1) printf("impossible\n");
		else printf("%d %d\n", (x + y) / 2, (x - y) / 2);
	}

	return 0;
}
