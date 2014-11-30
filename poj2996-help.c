#include <stdio.h>

#define N 8

struct board
{
	int x, y;
};

char buffer[100];
char chess[N][N];
struct board wk[1], wq[1], wr[2], wb[2], wn[2], wp[8];
struct board bk[1], bq[1], br[2], bb[2], bn[2], bp[8];

void
setboard(struct board *b, int x, int y)
{
	int i;

	i = 0;
	while (b[i].x != 0) i++;
	b[i].x = x;
	b[i].y = y;
}

int
main()
{
	int i, j;

	for (i = N - 1; i >= 0; i--)
	{
		scanf("%s", buffer);
		scanf("%s", buffer);
		for (j = 0; j < N; j++) chess[i][j] = buffer[2 + 4 * j];
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (chess[i][j] == 'K') setboard(wk, i + 1, j + 1);
			else if (chess[i][j] == 'Q') setboard(wq, i + 1, j + 1);
			else if (chess[i][j] == 'R') setboard(wr, i + 1, j + 1);
			else if (chess[i][j] == 'B') setboard(wb, i + 1, j + 1);
			else if (chess[i][j] == 'N') setboard(wn, i + 1, j + 1);
			else if (chess[i][j] == 'P') setboard(wp, i + 1, j + 1);
		}
	}
	for (i = N - 1; i >= 0; i--)
	{
		for (j = 0; j < N; j++)
		{
			if (chess[i][j] == 'k') setboard(bk, i + 1, j + 1);
			else if (chess[i][j] == 'q') setboard(bq, i + 1, j + 1);
			else if (chess[i][j] == 'r') setboard(br, i + 1, j + 1);
			else if (chess[i][j] == 'b') setboard(bb, i + 1, j + 1);
			else if (chess[i][j] == 'n') setboard(bn, i + 1, j + 1);
			else if (chess[i][j] == 'p') setboard(bp, i + 1, j + 1);
		}
	}
	printf("White: ");
	if (wk[0].x != 0) printf("K%c%d", 'a' + wk[0].y - 1, wk[0].x);
	if (wq[0].x != 0) printf(",Q%c%d", 'a' + wq[0].y - 1, wq[0].x);
	for (i = 0; i < 2; i++)
	{
		if (wr[i].x != 0) printf(",R%c%d", 'a' + wr[i].y - 1, wr[i].x);
		else break;
	}
	for (i = 0; i < 2; i++)
	{
		if (wb[i].x != 0) printf(",B%c%d", 'a' + wb[i].y - 1, wb[i].x);
		else break;
	}
	for (i = 0; i < 2; i++)
	{
		if (wn[i].x != 0) printf(",N%c%d", 'a' + wn[i].y - 1, wn[i].x);
		else break;
	}
	for (i = 0; i < 8; i++)
	{
		if (wp[i].x != 0) printf(",%c%d", 'a' + wp[i].y - 1, wp[i].x);
		else break;
	}
	printf("\n");
	printf("Black: ");
	if (bk[0].x != 0) printf("K%c%d", 'a' + bk[0].y - 1, bk[0].x);
	if (bq[0].x != 0) printf(",Q%c%d", 'a' + bq[0].y - 1, bq[0].x);
	for (i = 0; i < 2; i++)
	{
		if (br[i].x != 0) printf(",R%c%d", 'a' + br[i].y - 1, br[i].x);
		else break;
	}
	for (i = 0; i < 2; i++)
	{
		if (bb[i].x != 0) printf(",B%c%d", 'a' + bb[i].y - 1, bb[i].x);
		else break;
	}
	for (i = 0; i < 2; i++)
	{
		if (bn[i].x != 0) printf(",N%c%d", 'a' + bn[i].y - 1, bn[i].x);
		else break;
	}
	for (i = 0; i < 8; i++)
	{
		if (bp[i].x != 0) printf(",%c%d", 'a' + bp[i].y - 1, bp[i].x);
	}
	printf("\n");

	return 0;
}
