#include <stdio.h>

int s, v;
double t;

int
main()
{
	int th, tm, ts;

	s = v = 0;
	t = 0;
	while (scanf("%d:%d:%d", &th, &tm, &ts) != EOF)
	{
		if (getchar() == ' ')
		{
			t += (double)(3600 * th + 60 * tm + ts - s) / 3600 * v;
			s = 3600 * th + 60 * tm + ts;
			scanf("%d", &v);
		}
		else
		{
			printf("%02d:%02d:%02d %.2f km\n", th, tm, ts, t + (double)(3600 * th + 60 * tm + ts - s) / 3600 * v);
		}
	}

	return 0;
}
