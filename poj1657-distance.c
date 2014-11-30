#include <stdio.h>
#include <string.h>

int t;
char from[10], to[10];
int king, queen, rook, bishop;

int
max(int x, int y)
{
	return x > y? x: y;
}

int
line(char *x, char *y)
{
	return x[0] == y[0] || x[1] == y[1];
}

int
diag(char *x, char *y)
{
	if (abs(x[0] - y[0]) == abs(x[1] - y[1])) return 1;
	if (abs(x[0] - y[0]) % 2 == abs(x[1] - y[1]) % 2) return 0;
	return -1;
}

int
dist(char *x, char *y)
{
	return max(abs(x[0] - y[0]), abs(x[1] - y[1]));
}

int
main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s %s", from, to);

		if (strcmp(from, to) == 0)
		{
			king = queen = rook = bishop = 0;
		}
		else
		{
			int t1 = line(from, to), t2 = diag(from, to);

			king = dist(from, to);

			if (t1 == 1 || t2 == 1) queen = 1;
			else queen = 2;

			if (t1 == 1) rook = 1;
			else rook = 2;

			if (t2 == 1) bishop = 1;
			else if (t2 == 0) bishop = 2;
			else bishop = -1;
		}

		if (bishop == -1) printf("%d %d %d Inf\n", king, queen, rook);
		else printf("%d %d %d %d\n", king, queen, rook, bishop);
	}

	return 0;
}
