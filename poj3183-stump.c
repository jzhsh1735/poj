#include <stdio.h>

int n, last, now, next;

int
main()
{
	int i;

	scanf("%d", &n);
	last = now = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &next);
		if (last <= now && now >= next && i > 0) printf("%d\n", i);
		last = now;
		now = next;
	}
	if (last <= now) printf("%d\n", n);

	return 0;
}
