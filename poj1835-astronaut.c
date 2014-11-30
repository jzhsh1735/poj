#include <stdio.h>
#include <string.h>

int reverse[6] = {3, 4, 5, 0, 1, 2};

int t, n;
int x, y, z;
int p, h, l;

char cmd[100];
int s;

int
main()
{
	int i, temp;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		x = y = z = 0;
		p = 0; h = 2; l = 4;
		for (i = 0; i < n; i++)
		{
			scanf("%s %d", cmd, &s);

			if (strcmp(cmd, "back") == 0)
			{
				p = reverse[p];
				l = reverse[l];
			}
			if (strcmp(cmd, "left") == 0)
			{
				temp = p;
				p = l;
				l = reverse[temp];
			}
			if (strcmp(cmd, "right") == 0)
			{
				temp = p;
				p = reverse[l];
				l = temp;
			}
			if (strcmp(cmd, "up") == 0)
			{
				temp = p;
				p = h;
				h = reverse[temp];
			}
			if (strcmp(cmd, "down") == 0)
			{
				temp = p;
				p = reverse[h];
				h = temp;
			}

			if (p == 0) x += s;
			if (p == 1) y += s;
			if (p == 2) z += s;
			if (p == 3) x -= s;
			if (p == 4) y -= s;
			if (p == 5) z -= s;
		}
		printf("%d %d %d %d\n", x, y, z, p);
	}

	return 0;
}
