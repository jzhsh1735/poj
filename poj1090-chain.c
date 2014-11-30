#include <stdio.h>

#define N 1000
#define M 500

int n;
int ring[N];
int a[N][M], b[N][M], c[N][M];

int
main()
{
	int i, j, k;

	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &ring[i]);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++) a[i][j] = b[i][j] = c[i][j] = 0;
	}
	a[0][0] = ring[0];
	b[0][0] = 1 - ring[0];
	c[0][0] = 1;
	for (i = 1; i < n; i++)
	{
		if (ring[i] == 0)
		{
			for (j = 0; j < M; j++) a[i][j] = a[i - 1][j];
			k = 1;
			for (j = 0; j < M; j++)
			{
				b[i][j] = (b[i - 1][j] + c[i - 1][j] + k) % 10;
				k = (b[i - 1][j] + c[i - 1][j] + k) / 10;
			}
		}
		else
		{
			k = 1;
			for (j = 0; j < M; j++)
			{
				a[i][j] = (b[i - 1][j] + c[i - 1][j] + k) % 10;
				k = (b[i - 1][j] + c[i - 1][j] + k) / 10;
			}
			for (j = 0; j < M; j++) b[i][j] = a[i - 1][j];
		}
		k = 1;
		for (j = 0; j < M; j++)
		{
			c[i][j] = (2 * c[i - 1][j] + k) % 10;
			k = (2 * c[i - 1][j] + k) / 10;
		}
	}
	i = M - 1;
	while (a[n - 1][i] == 0) i--;
	if (i < 0) printf("0");
	while (i >= 0)
	{
		printf("%d", a[n - 1][i]);
		i--;
	}
	printf("\n");

	return 0;
}
