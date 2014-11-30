#include <stdio.h>

int m, t, u, f, d;
char str[10];

int
main()
{
	int i, ans = 0;

	scanf("%d %d %d %d %d", &m, &t, &u, &f, &d);
	for (i = 0; i < t; i++)
	{
		scanf("%s", str);
		if (str[0] == 'f') m -= 2 * f;
		if (str[0] == 'u' || str[0] == 'd') m -= u + d;

		if (m >= 0) ans++;
		else break;
	}

	printf("%d\n", ans);

	return 0;
}
