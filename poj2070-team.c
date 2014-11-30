#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ZERO 1e-8

char name[3][50] = {"Wide Receiver", "Lineman", "Quarterback"};
double speed[3] = {4.5, 6.0, 5.0};
int weight[3] = {150, 300, 200};
int strength[3] = {200, 500, 300};

int
main()
{
	int i, flag;

	double tspeed;
	int tweight, tstrength;

	//while (scanf("%lf %d %d", &tspeed, &tweight, &tstrength), fabs(tspeed) > ZERO && tweight && tstrength)
	while (scanf("%lf %d %d", &tspeed, &tweight, &tstrength) != EOF)
	{
		if (fabs(tspeed) < ZERO && tweight == 0 && tstrength == 0) break;

		flag = 0;
		for (i = 0; i < 3; i++)
		{
			if (speed[i] >= tspeed && weight[i] <= tweight && strength[i] <= tstrength)
			{
				flag = 1;
				printf("%s ", name[i]);
			}
		}
		if (flag == 0) printf("No positions");
		printf("\n");
	}

	return 0;
}
