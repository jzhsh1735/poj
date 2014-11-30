#include <stdio.h>

int n, m, c;
int cons[100];
int flag[100];

int
main()
{
	int i, max, t1, t2, cnt = 0, ans;

	//while (scanf("%d %d %d", &n, &m, &c), n && m && c)
	while (scanf("%d %d %d", &n, &m, &c) != EOF)
	{
		if (n == 0 && m == 0 && c == 0) break;

		for (i = 0; i < n; i++) scanf("%d", &cons[i]);
		for (i = 0; i < n; i++) flag[i] = 0;

		ans = t2 = max = 0;
		for (i = 0; i < m; i++)
		{
			scanf("%d", &t1);
			if (flag[t1 - 1] == 0)
			{
				t2 += cons[t1 - 1];
				flag[t1 - 1] = 1;
				if (t2 > c) ans = 1;
				if (t2 > max) max = t2;
			}
			else
			{
				t2 -= cons[t1 - 1];
				flag[t1 - 1] = 0;
			}
		}

		cnt++;
		printf("Sequence %d\n", cnt);
		if (ans == 0) printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", max);
		else printf("Fuse was blown.\n\n");
	}

	return 0;
}
