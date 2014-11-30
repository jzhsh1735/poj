#include <stdio.h>

int n, q;
int cnt[100];

int
main()
{
	int i, j, t1, t2, ans;

	while (scanf("%d %d", &n, &q) != EOF)
	{
		if (n == 0 && q == 0) break;

		for (i = 0; i < 100; i++) cnt[i] = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &t1);
			for (j = 0; j < t1; j++)
			{
				scanf("%d", &t2);
				cnt[t2]++;
			}
		}
		ans = 0;
		for (i = 0; i < 100; i++)
		{
			if (cnt[i] > cnt[ans]) ans = i;
		}

		if (cnt[ans] >= q) printf("%d\n", ans);
		else printf("0\n");
	}

	return 0;
}
