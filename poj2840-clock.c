#include <stdio.h>

int t, h, m;

int
main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d:%d", &h, &m);
		if (m != 0) printf("0\n");
		else printf("%d\n", h <= 12? h + 12: h - 12);
	}

	return 0;
}
