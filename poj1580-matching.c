#include <stdio.h>
#include <string.h>

char str[2][100];

int
match(char *x, char *y)
{
	int i, result = 0;

	for (i = 0; i < strlen(x) && i < strlen(y); i++)
	{
		if (x[i] == y[i]) result++;
	}

	return result;
}

int
gcd(int x, int y)
{
	return y == 0? x: gcd(y, x % y);
}

int
main()
{
	int i, j;

	while (scanf("%s", str[0]), strcmp(str[0], "-1") != 0)
	{
		scanf("%s", str[1]);

		int ans1 = 0, ans2 = strlen(str[0]) + strlen(str[1]), temp;
		for (i = 0; i < strlen(str[0]); i++)
		{
			temp = match(str[0] + i, str[1]);
			if (ans1 < temp) ans1 = temp;
		}

		for (i = 0; i < strlen(str[1]); i++)
		{
			temp = match(str[0], str[1] + i);
			if (ans1 < temp) ans1 = temp;
		}
		ans1 *= 2;

		if (ans1 == 0) printf("appx(%s,%s) = 0\n", str[0], str[1]);
		else if (ans1 == ans2) printf("appx(%s,%s) = 1\n", str[0], str[1]);
		else printf("appx(%s,%s) = %d/%d\n", str[0], str[1], ans1 / gcd(ans1, ans2), ans2 / gcd(ans1, ans2));
	}

	return 0;
}
