#include <stdio.h>
#include <stdlib.h>

struct car
{
	int idx;
	int pos;
};

int t, h, l;
struct car c[100];
int ans;

int
compare(const void *x, const void *y)
{
	return ((struct car *)x)->idx - ((struct car *)y)->idx;
}

int
main()
{
	int i, j;
	int temp, cnt, dist;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &h, &l);
		ans = 0;
		for (i = 0; i < h; i++)
		{
			cnt = 0;
			for (j = 0; j < l; j++)
			{
				scanf("%d", &temp);
				if (temp > 0)
				{
					c[cnt].idx = temp;
					c[cnt].pos = j;
					cnt++;
				}
			}
			qsort(c, cnt, sizeof(struct car), compare);
			temp = 0;
			for (j = 0; j < cnt; j++)
			{
				dist = abs(temp - c[j].pos);
				ans += 5 * (dist < l - dist? dist: l - dist);
				temp = c[j].pos;
			}
			ans += 2 * cnt * i * 10;
		}
		printf("%d\n", ans);
	}

	return 0;
}
