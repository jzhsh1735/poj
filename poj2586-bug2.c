#include <stdio.h>

int s, d;

int
main()
{
	while (scanf("%d %d", &s, &d) != EOF)
	{
		if (d > 4 * s)
		{
			if (10 * s - 2 * d > 0) printf("%d\n", 10 * s - 2 * d);
			else printf("Deficit\n");
		}
		else if (2 * d > 3 * s)
		{
			if (8 * s - 4 * d > 0) printf("%d\n", 8 * s - 4 * d);
			else printf("Deficit\n");
		}
		else if (3 * d > 2 * s)
		{
			if (6 * s - 6 * d > 0) printf("%d\n", 6 * s - 6 * d);
			else printf("Deficit\n");
		}
		else if (4 * d > s)
		{
			if (3 * s - 9 * d > 0) printf("%d\n", 3 * s - 9 * d);
			else printf("Deficit\n");
		}
		else printf("Deficit\n");
	}

	return 0;
}
