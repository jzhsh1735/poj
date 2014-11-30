#include <stdio.h>

int r[16], g[16], b[16];
int tr, tg, tb;

int
main()
{
	int i;
	for (i = 0; i < 16; i++) scanf("%d %d %d", &r[i], &g[i], &b[i]);

	while (1)
	{
		scanf("%d %d %d", &tr, &tg, &tb);
		if (tr < 0 && tg < 0 && tb < 0) break;

		int index, value;
		index = -1;
		for (i = 0; i < 16; i++)
		{
			int temp = (tr - r[i]) * (tr - r[i]) + (tg - g[i]) * (tg - g[i]) + (tb - b[i]) * (tb - b[i]);
			if (index < 0 || value > temp)
			{
				index = i;
				value = temp;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", tr, tg, tb, r[index], g[index], b[index]);
	}

	return 0;
}
