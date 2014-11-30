#include <stdio.h>

int n, m, r, c;
char pix[200][200];
int ans;

int
main()
{
	int i, j, k, l;

	while (scanf("%d %d %d %d", &n, &m, &r, &c) != EOF)
	{
		if (n == 0 && m == 0 && r == 0 && c == 0) break;

		for (i = 0; i < n; i++) scanf("%s", pix[i]);
		ans = 0;
		for (i = 0; i < n && ans >= 0; i++)
		{
			for (j = 0; j < m && ans >= 0; j++)
			{
				if (pix[i][j] != '0')
				{
					if (i + r - 1 >= n || j + c - 1 >= m) ans = -1;
					else
					{
						ans++;
						for (k = 0; k < r; k++)
						{
							for (l = 0; l < c; l++)
							{
								if (pix[i + k][j + l] == '0') pix[i + k][j + l] = '1';
								else pix[i + k][j + l] = '0';
							}
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
