#include <stdio.h>

int n, r, e, c;

int
main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d %d", &r, &e, &c);
		if (r + c < e) printf("advertise\n");
		else if (r + c == e) printf("does not matter\n");
		else printf("do not advertise\n");
	}

	return 0;
}
