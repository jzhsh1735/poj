#include <stdio.h>

int n;
int num[10000];
int n2, n3, n5, n7;

int
min(int x, int y)
{
	return x > y? y: x;
}

int
main()
{
	int i;

	num[0] = 1;
	n2 = n3 = n5 = n7 = 0;
	for (i = 1; i < 5842; i++)
	{
		num[i] = min(min(min(num[n2] * 2, num[n3] * 3), num[n5] * 5), num[n7] * 7);
		if (num[i] == num[n2] * 2) n2++;
		if (num[i] == num[n3] * 3) n3++;
		if (num[i] == num[n5] * 5) n5++;
		if (num[i] == num[n7] * 7) n7++;
	}

	while (scanf("%d", &n), n)
	{
		if (n % 10 == 1 && n % 100 != 11) printf("The %dst humble number is %d.\n", n, num[n - 1]);
		else if (n % 10 == 2 && n % 100 != 12) printf("The %dnd humble number is %d.\n", n, num[n - 1]);
		else if (n % 10 == 3 && n % 100 != 13) printf("The %drd humble number is %d.\n", n, num[n - 1]);
		else printf("The %dth humble number is %d.\n", n, num[n - 1]);
	}

	return 0;
}
