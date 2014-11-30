#include <stdio.h>

char wff[200];
int var[5];
int ptr;
int flag;

int
val()
{
	int i, j;

	ptr++;
	if (wff[ptr] == 'K')
	{
		i = val();
		j = val();
		if (i == 1 && j == 1) return 1;
		else return 0;
	}
	else if (wff[ptr] == 'A')
	{
		i = val();
		j = val();
		if (i == 1 || j == 1) return 1;
		else return 0;
	}
	else if (wff[ptr] == 'N')
	{
		i = val();
		if (i == 0) return 1;
		else return 0;
	}
	else if (wff[ptr] == 'C')
	{
		i = val();
		j = val();
		if (i == 1 && j == 0) return 0;
		else return 1;
	}
	else if (wff[ptr] == 'E')
	{
		i = val();
		j = val();
		if (i == j) return 1;
		else return 0;
	}
	else
	{
		return var[wff[ptr] - 'p'];
	}
}

int
main()
{
	while (scanf("%s", wff), strcmp(wff, "0") != 0)
	{
		flag = 1;
		for (var[0] = 0; var[0] < 2 && flag; var[0]++)
		{
			for (var[1] = 0; var[1] < 2 && flag; var[1]++)
			{
				for (var[2] = 0; var[2] < 2 && flag; var[2]++)
				{
					for (var[3] = 0; var[3] < 2 && flag; var[3]++)
					{
						for (var[4] = 0; var[4] < 2 && flag; var[4]++)
						{
							ptr = -1;
							flag = val();
						}
					}
				}
			}
		}
		printf("%s\n", (flag == 1? "tautology": "not"));
	}

	return 0;
}
