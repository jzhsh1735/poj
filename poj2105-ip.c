#include <stdio.h>

int n;
char str[100];
int ip[10];

int
main()
{
	int i;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", str);

		for (i = 0; i < 4; i++) ip[i] = 0;
		for (i = 0; i < 32; i++) ip[i / 8] = 2 * ip[i / 8] + str[i] - '0';

		printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
	}

	return 0;
}
