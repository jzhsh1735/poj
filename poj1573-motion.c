#include <stdio.h>

int r, c, e;
char instr[100][100];
int path[100][100];
int x, y, step;

int
main()
{
	int i, j;

	while (scanf("%d %d %d", &r, &c, &e) != EOF)
	{
		if (r == 0 && c == 0 && e == 0) break;
		for (i = 0; i < r; i++) scanf("%s", instr[i]);

		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++) path[i][j] = -1;
		}
		x = 0;
		y = e - 1;
		step = 0;
		while (1)
		{
			path[x][y] = step;
			if (instr[x][y] == 'N') x--;
			else if (instr[x][y] == 'S') x++;
			else if (instr[x][y] == 'W') y--;
			else if (instr[x][y] == 'E') y++;
			step++;
			if (x < 0 || y < 0 || x >= r || y >= c)
			{
				printf("%d step(s) to exit\n", step);
				break;
			}
			if (path[x][y] != -1)
			{
				printf("%d step(s) before a loop of %d step(s)\n", path[x][y], step - path[x][y]);
				break;
			}
		}
	}

	return 0;
}
