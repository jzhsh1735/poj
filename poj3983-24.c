#include <stdio.h>
#include <math.h>

#define ZERO 1e-8

int a, b, c, d;
char oper[] = "+-*/";

double
calc(double x, double y, int oper)
{
	if (oper == 0) return x + y;
	else if (oper == 1) return x - y;
	else if (oper == 2) return x * y;
	else return x / y;
}

int
check(int oper1, int oper2, int oper3, int type)
{
	double result;

	if (type == 0)
	{
		// ((a b) (c d))
		result = calc(calc(a, b, oper1), calc(c, d, oper3), oper2);
	}
	else if (type == 1)
	{
		// (((a b) c) d)
		result = calc(calc(calc(a, b, oper1), c, oper2), d, oper3);
	}
	else if (type == 2)
	{
		// ((a (b c)) d)
		result = calc(calc(a, calc(b, c, oper2), oper1), d, oper3);
	}
	else if (type == 3)
	{
		// (a ((b c) d))
		result = calc(a, calc(calc(b, c, oper2), d, oper3), oper1);
	}
	else
	{
		// (a (b (c d)))
		result = calc(a, calc(b, calc(c, d, oper3), oper2), oper1);
	}

	return fabs(result - 24) < ZERO;
}

int
main()
{
	int i, j, k, l;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
			{
				for (l = 0; l < 5; l++)
				{
					if (check(i, j, k, l))
					{
						// ((a b) (c d))
						if (l == 0) printf("(%d%c%d)%c(%d%c%d)\n", a, oper[i], b, oper[j], c, oper[k], d);
						// (((a b) c) d)
						else if (l == 1) printf("((%d%c%d)%c%d)%c%d\n", a, oper[i], b, oper[j], c, oper[k], d);
						// ((a (b c)) d)
						else if (l == 2) printf("(%d%c(%d%c%d))%c%d\n", a, oper[i], b, oper[j], c, oper[k], d);
						// (a ((b c) d))
						else if (l == 3) printf("%d%c((%d%c%d)%c%d)\n", a, oper[i], b, oper[j], c, oper[k], d);
						// (a (b (c d)))
						else printf("%d%c(%d%c(%d%c%d))\n", a, oper[i], b, oper[j], c, oper[k], d);
					}
				}
			}
		}
	}

	return 0;
}
