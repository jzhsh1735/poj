#include <stdio.h>

#define N 10000000

int set[N];
int n;

int
main()
{
	int i, base2, base3;

	set[0] = 1;
	base2 = base3 = 0;
	for (i = 1; i < N; i++)
	{
		if (set[base2] * 2 + 1 < set[base3] * 3 + 1)
		{
			set[i] = set[base2] * 2 + 1;
			base2++;
		}
		else if (set[base2] * 2 + 1 > set[base3] * 3 + 1)
		{
			set[i] = set[base3] * 3 + 1;
			base3++;
		}
		else
		{
			set[i] = set[base2] * 2 + 1;
			base2++;
			base3++;
		}
	}

	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", set[n - 1]);
	}

	return 0;
}
