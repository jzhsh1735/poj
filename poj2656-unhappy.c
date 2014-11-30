#include <stdio.h>

int n;

int
main()
{
	int i;

	while (scanf("%d", &n), n)
	{
		int t1, t2, max = 0, index;
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &t1, &t2);
			if (t1 + t2 > max)
			{
				max = t1 + t2;
				index = i + 1;
			}
		}

		if (max > 8) printf("%d\n", index);
		else printf("0\n");
	}

	return 0;
}
