#include <stdio.h>

char square[10][10];
int ans;

int
success()
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (square[0][0] != square[i][j]) return 0;
		}
	}

	return 1;
}

void
flip(int x, int y)
{
	square[x][y] = (square[x][y] == 'b'? 'w': 'b');
	if (x - 1 >= 0) square[x - 1][y] = (square[x - 1][y] == 'b'? 'w': 'b');
	if (y - 1 >= 0) square[x][y - 1] = (square[x][y - 1] == 'b'? 'w': 'b');
	if (x + 1 < 4) square[x + 1][y] = (square[x + 1][y] == 'b'? 'w': 'b');
	if (y + 1 < 4) square[x][y + 1] = (square[x][y + 1] == 'b'? 'w': 'b');
}

int
dfs(int x, int y, int dep)
{
	if (ans == dep) return success();
	if (x > 3 || y > 3) return 0;

	flip(x, y);
	if (x + 1 < 4 && dfs(x + 1, y, dep + 1)) return 1;
	else if (dfs(0, y + 1, dep + 1)) return 1;
	flip(x, y);
	
	if (x + 1 < 4) return dfs(x + 1, y, dep);
	else return dfs(0, y + 1, dep);
}

int
main()
{
	int i;

	for (i = 0; i < 4; i++) scanf("%s", square[i]);
	for (i = 0; i <= 16; i++)
	{
		ans = i;
		if (dfs(0, 0, 0) == 1) break;
	}
	if (i > 16) printf("Impossible\n");
	else printf("%d\n", i);

	return 0;
}
