#include <stdio.h>

int t, n;
int cnt[200];

int
main()
{
	int i, j, from, to;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < 200; i++) cnt[i] = 0;

		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &from, &to);
			if (from % 2 == 0) from = from / 2 - 1;
			else from = from / 2;
			if (to % 2 == 0) to = to / 2 - 1;
			else to = to / 2;

			for (j = (from > to? to: from); j <= (from > to? from: to); j++) cnt[j]++;
		}

		int ans = 0;
		for (i = 0; i < 200; i++) ans = (cnt[i] > ans? cnt[i]: ans);

		printf("%d\n", ans * 10);
	}

	return 0;
}
