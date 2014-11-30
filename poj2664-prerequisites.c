#include <stdio.h>
#include <string.h>

int k, m, c, r;
char chosen[100][5];
char category[100][5];

int
main()
{
	int i, j;
	int ans;

	while (scanf("%d", &k), k)
	{
		scanf("%d", &m);
		for (i = 0; i < k; i++) scanf("%s", chosen[i]);
		ans = 1;
		while (m--)
		{
			scanf("%d %d", &c, &r);
			for (i = 0; i < c; i++) scanf("%s", category[i]);
			if (ans == 1)
			{
				for (i = 0; i < k; i++)
				{
					for (j = 0; j < c; j++)
					{
						if (strcmp(chosen[i], category[j]) == 0)
						{
							r--;
							break;
						}
					}
				}
				if (r > 0) ans = 0;
			}
		}
		if (ans == 1) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}
