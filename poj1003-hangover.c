#include <stdio.h>

#define NUM 700
double len[NUM];

int
main()
{
	//int i = 1;
	//double len = 0;
	//while (len < 6)
	//{
	//	len += 1.0 / (i + 1);
	//	i++;
	//}
	//printf("%d\n", i);

	int i;
	for (i = 0; i < NUM; i++)
	{
		if (i == 0) len[i] = 0;
		else len[i] = len[i - 1] + 1.0 / (i + 1);
	}

	char buffer[256];
	double query;
	while (1)
	{
		scanf("%s", buffer);
		if (strcmp(buffer, "0.00") == 0) break;

		sscanf(buffer, "%lf", &query);
		for (i = 0; i < NUM; i++)
		{
			if (len[i] >= query)
			{
				printf("%d card(s)\n", i);
				break;
			}
		}
	}

	return 0;
}
