#include <stdio.h>

#define M 2000000
#define N 100000

int flag[M];
int prime[N];
int n;

int
find(int l, int r)
{
	if (l == r) return l;

	int m = (l + r) / 2;
	if (n < prime[m]) return find(l, m);
	else if (prime[m + 1] <= n) return find(m + 1, r);
	else return m;
}

int
main()
{
	int i, j, k;

	for (i = 0; i < M; i++) flag[i] = 0;
	for (i = 2, j = 0; i < M && j < N; i++)
	{
		if (flag[i] == 1) continue;
		prime[j] = i;
		j++;
		for (k = i + i; k < M; k += i) flag[k] = 1;
	}

	while (scanf("%d", &n), n)
	{
		i = find(0, N - 1);
		if (prime[i] == n) printf("0\n");
		else printf("%d\n", prime[i + 1] - prime[i]);
	}

	return 0;
}
