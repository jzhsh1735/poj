#include <stdio.h>
#include <stdlib.h>

struct shelf
{
	int y, x, l, x1, x2;
};

int XN, YN, XT, YT;
int N;
struct shelf s[100];
int minpeg, minplank;

int
compare(const void *x, const void *y)
{
	return ((struct shelf *)x)->y - ((struct shelf *)y)->y;
}

int
main()
{
	int i, j, k;
	int temppeg, tempplank, temp;

	scanf("%d %d %d %d", &XN, &YN, &XT, &YT);
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d %d %d %d %d", &s[i].y, &s[i].x, &s[i].l, &s[i].x1, &s[i].x2);

	minpeg = minplank = -1;
	qsort(s, N, sizeof(struct shelf), compare);
	for (i = 0; i < N; i++)
	{
		if (s[i].y + YT > YN) break;
		if (XT > s[i].l) continue;
		for (j = 0; j + XT <= XN; j++)
		{
			temppeg = tempplank = 0;
			// XT
			if (j + s[i].l < s[i].x + s[i].x1 || s[i].x + s[i].x2 + s[i].l < j + XT) continue;
			if (2 * (s[i].x + s[i].x1 - j) > s[i].l || 2 * (j + XT - s[i].x - s[i].x2) > s[i].l ||
				j + s[i].l < s[i].x + s[i].x2 || j + XT - s[i].l > s[i].x + s[i].x1) temppeg++;
			// YT
			for (k = i + 1; k < N; k++)
			{
				if (s[i].y + YT <= s[k].y) break;
				if (s[k].x + s[k].l <= j || s[k].x >= j + XT) continue;
				else if (s[k].x + s[k].x2 <= j)
				{
					if (2 * (s[k].x + s[k].x1) <= j && 2 * (s[k].x + s[k].x2) >= j) temp = j;
					else if (2 * (s[k].x + s[k].x1) > j) temp = 2 * (j - s[k].x - s[k].x1);
					else temp = 2 * (s[k].x + s[k].x2);
					if (s[k].l > temp) tempplank += s[k].l - temp;
				}
				else if (s[k].x + s[k].x1 >= j + XT)
				{
					if (2 * (s[k].x + s[k].x1) <= j + XT + XN && 2 * (s[k].x + s[k].x2) >= j + XT + XN) temp = XN - j - XT;
					else if (2 * (s[k].x + s[k].x1) > j + XT + XN) temp = 2 * (XN - s[k].x - s[k].x1);
					else temp = 2 * (s[k].x + s[k].x2 - j - XT);
					if (s[k].l > temp) tempplank += s[k].l - temp;
				}
				else if (s[k].x + s[k].x1 <= j && s[k].x + s[k].x2 > j && s[k].x + s[k].x2 < j + XT)
				{
					if (j == 0)
					{
						temppeg += 2;
						tempplank += s[k].l;
					}
					else
					{
						temppeg++;
						if (s[k].l > j) tempplank += s[k].l - j;
					}
				}
				else if (s[k].x + s[k].x1 > j && s[k].x + s[k].x1 < j + XT && s[k].x + s[k].x2 >= j + XT)
				{
					if (j + XT == XN)
					{
						temppeg += 2;
						tempplank += s[k].l;
					}
					else
					{
						temppeg++;
						if (s[k].l > XN - j - XT) tempplank += s[k].l - XN + j + XT;
					}
				}
				else if (s[k].x + s[k].x1 <= j && s[k].x + s[k].x2 >= j + XT)
				{
					if (j == 0 && j + XT == XN)
					{
						temppeg += 2;
						tempplank += s[k].l;
					}
					else
					{
						temppeg++;
						temp = (j > (XN - j - XT)? j: (XN - j - XT));
						if (s[k].l > temp) tempplank += s[k].l - temp;
					}
				}
				else if (s[k].x + s[k].x1 > j && s[k].x + s[k].x2 < j + XT)
				{
					temppeg += 2;
					tempplank += s[k].l;
				}
			}
			if (minpeg < 0 || temppeg < minpeg || temppeg == minpeg && tempplank < minplank)
			{
				minpeg = temppeg;
				minplank = tempplank;
			}
		}
	}
	printf("%d %d\n", minpeg, minplank);

	return 0;
}
