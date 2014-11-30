#include <stdio.h>
#include <stdlib.h>

int score[10];

int
compare(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

int
main()
{
	int i;

	while (1)
	{
		for (i = 0; i < 6; i++) scanf("%d", &score[i]);
		qsort(score, 6, sizeof(int), compare);

		if (score[0] == 0 && score[5] == 0) break;

		double sum = 0;
		for (i = 1; i < 5; i++) sum += score[i];
		sum /= 4;

		printf("%g\n", sum);
	}

	return 0;
}
