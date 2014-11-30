#include <stdio.h>

int n;
char str[100][100];

int
main()
{
	int i, cnt = 0;

	while (scanf("%d", &n), n)
	{
		for (i = 0; i < n; i++) scanf("%s", str[i]);

		cnt++;
		printf("SET %d\n", cnt);
		for (i = 0; i < n; i += 2) printf("%s\n", str[i]);
		for (i = (n % 2 == 0? n - 1: n - 2); i > 0; i -= 2) printf("%s\n", str[i]);
	}

	return 0;
}
