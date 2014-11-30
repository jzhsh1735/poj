#include <stdio.h>

int n, m;

int
main()
{
	int i, j, t1, t2;

	scanf("%d %d", &n, &m);
	int ans = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &t1);
		t2 = 1;
		for (j = 0; j < m; j++) t2 *= t1;
		if (t2 > 0) ans += t2;
	}

	printf("%d\n", ans);

	return 0;
}
