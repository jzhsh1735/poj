#include <stdio.h>

int n;
int result[2000];

int
main()
{
	int i, p2, p3, p5;

	result[1] = 1;
	p2 = p3 = p5 = 1;
	for (i = 2; i <= 1500; i++)
	{
		int t2 = result[p2] * 2;
		int t3 = result[p3] * 3;
		int t5 = result[p5] * 5;

		if (t2 < t3 && t2 < t5)
		{
			result[i] = t2;
			p2++;
		}
		if (t3 < t2 && t3 < t5)
		{
			result[i] = t3;
			p3++;
		}
		if (t5 < t2 && t5 < t3)
		{
			result[i] = t5;
			p5++;
		}
		if (t2 == t3 && t2 < t5)
		{
			result[i] = t2;
			p2++; p3++;
		}
		if (t2 == t5 && t2 < t3)
		{
			result[i] = t2;
			p2++; p5++;
		}
		if (t3 == t5 && t3 < t2)
		{
			result[i] = t3;
			p3++; p5++;
		}
		if (t2 == t3 && t2 == t5)
		{
			result[i] = t2;
			p2++; p3++; p5++;
		}
	}
	
	while (scanf("%d", &n), n)
	{
		printf("%d\n", result[n]);
	}
	
	return 0;
}
