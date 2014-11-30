#include <stdio.h>
#include <string.h>

char chess[17][50] = {
	"+---+---+---+---+---+---+---+---+",
	"|...|:::|...|:::|...|:::|...|:::|",
	"+---+---+---+---+---+---+---+---+",
	"|:::|...|:::|...|:::|...|:::|...|",
	"+---+---+---+---+---+---+---+---+",
	"|...|:::|...|:::|...|:::|...|:::|",
	"+---+---+---+---+---+---+---+---+",
	"|:::|...|:::|...|:::|...|:::|...|",
	"+---+---+---+---+---+---+---+---+",
	"|...|:::|...|:::|...|:::|...|:::|",
	"+---+---+---+---+---+---+---+---+",
	"|:::|...|:::|...|:::|...|:::|...|",
	"+---+---+---+---+---+---+---+---+",
	"|...|:::|...|:::|...|:::|...|:::|",
	"+---+---+---+---+---+---+---+---+",
	"|:::|...|:::|...|:::|...|:::|...|",
	"+---+---+---+---+---+---+---+---+"
	};
char buffer[100];
char c;
int x, y;


int
main()
{
	int i;

	scanf("%s", buffer);
	scanf("%s", buffer);
	c = 'P';
	for (i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] == 'K') c = 'K';
		else if (buffer[i] == 'Q') c = 'Q';
		else if (buffer[i] == 'R') c = 'R';
		else if (buffer[i] == 'B') c = 'B';
		else if (buffer[i] == 'N') c = 'N';
		else if (buffer[i] >= 'a' && buffer[i] <= 'h') x = buffer[i] - 'a' + 1;
		else if (buffer[i] >= '1' && buffer[i] <= '8')
		{
			y = buffer[i] - '1' + 1;
			chess[17 - 2 * y][4 * x - 2] = c;
			c = 'P';
		}
	}
	scanf("%s", buffer);
	scanf("%s", buffer);
	c = 'p';
	for (i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] == 'K') c = 'k';
		else if (buffer[i] == 'Q') c = 'q';
		else if (buffer[i] == 'R') c = 'r';
		else if (buffer[i] == 'B') c = 'b';
		else if (buffer[i] == 'N') c = 'n';
		else if (buffer[i] >= 'a' && buffer[i] <= 'h') x = buffer[i] - 'a' + 1;
		else if (buffer[i] >= '1' && buffer[i] <= '8')
		{
			y = buffer[i] - '1' + 1;
			chess[17 - 2 * y][4 * x - 2] = c;
			c = 'p';
		}
	}
	for (i = 0; i < 17; i++) printf("%s\n", chess[i]);

	return 0;
}
