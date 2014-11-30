#include <stdio.h>

int n, k, s, t, r;

int
main()
{
	int ans;

	scanf("%d %d", &n, &k);
	while (k--)
	{
		scanf("%d %d %d", &s, &t, &r);

		ans = n / s + (n % s == 0? 0: 1);
		ans += (ans / t - (ans % t == 0? 1: 0)) * r;

		printf("%d\n", ans);
	}

	return 0;
}
