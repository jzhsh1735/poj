#include <stdio.h>
#include <string.h>

int r, c;
int pix[10][10];
char buffer[100];

int
main()
{
	int i, j;

	while (scanf("%s", buffer), strcmp(buffer, "ENDOFINPUT") != 0)
	{
		scanf("%d %d", &r, &c);
		for (i = 0; i < r; i++)
		{
			getchar();
			for (j = 0; j < c; j++) pix[i][j] = getchar() - '0';
		}
		scanf("%s", buffer);

		for (i = 0; i < r - 1; i++)
		{
			for (j = 0; j < c - 1; j++)
			{
				pix[i][j] = (pix[i][j] + pix[i + 1][j] + pix[i][j + 1] + pix[i + 1][j + 1]) / 4;
				printf("%d", pix[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
