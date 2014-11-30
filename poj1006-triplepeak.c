#include <stdio.h>

int
main()
{
	int cnt = 0;
	int p, e, i, d, res;
	while (1)
	{
		scanf("%d %d %d %d\n", &p, &e, &i, &d);
		if (p == -1) break;

		p %= 23;
		e %= 28;
		i %= 33;
		res = 0;
		
		if (d % 23 == p && d % 28 == e && d % 33 == i) res = 23 * 28 * 33;

		while ((d + res) % 23 != p) res++;
		while ((d + res) % 28 != e) res += 23;
		while ((d + res) % 33 != i) res += 23 * 28;

		cnt++;
		printf("Case %d: the next triple peak occurs in %d days.\n", cnt, res);
	}

	return 0;
}
