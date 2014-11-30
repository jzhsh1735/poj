#include <stdio.h>
#include <stdlib.h>

struct player
{
	int data;
	int cnt;
};

int n, m;
struct player p[10000];

int
compare(const void *x, const void *y)
{
	if (((struct player *)x)->cnt == ((struct player *)y)->cnt) return ((struct player *)x)->data - ((struct player *)y)->data;
	else return ((struct player *)y)->cnt - ((struct player *)x)->cnt;
}

int
main()
{
	int i;

	//while (scanf("%d %d", &n, &m), n && m)
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0) break;

		for (i = 0; i < 10000; i++)
		{
			p[i].data = i + 1;
			p[i].cnt = 0;
		}

		int temp;
		for (i = 0; i < n * m; i++)
		{
			scanf("%d", &temp);
			p[temp - 1].cnt++;
		}
		qsort(p, 10000, sizeof(struct player), compare);

		temp = p[1].cnt;
		i = 1;
		while (p[i].cnt == temp)
		{
			printf("%d ", p[i].data);
			i++;
		}
		printf("\n");
	}

	return 0;
}
