#include <stdio.h>
#include <stdlib.h>

long long
gcd(long long x, long long y)
{
	return y == 0? x: gcd(y, x % y);
}

int
extended_gcd(long long a, long long b, long long *x, long long *y)
{
	long long tx, ty;
	if (b == 0)
	{
		*x = 1;
		*y = 0;
	}
	else
	{
		extended_gcd(b, a % b, &tx, &ty);
		*x = ty;
		*y = tx - a / b * ty;
	}

	return 0;
}

int
main()
{
	long long x, y, m, n, l, a, b, d, r, s, k;
	scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l);

	a = n - m;
	b = l;
	d = x - y;
	r = gcd(abs(a), abs(b));

	if (d % r != 0)
	{
		printf("Impossible\n");
	}
	else
	{
		a /= r; b /= r; d /= r;
		extended_gcd(abs(a), abs(b), &s, &k);

		if (a < 0) s *= -1;
		if (b < 0) k *= -1;

		s *= d;
		k *= d;

		s %= abs(b);
		if (s < 0) s += abs(b);

		printf("%lld\n", s);
	}
	
	return 0;
}
