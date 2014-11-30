#include <stdio.h>

int A, a, B, b, P;

int
main()
{
	scanf("%d %d %d %d %d", &A, &a, &B, &b, &P);
	if (P >= B && b >= A || P >= A && a >= B || P >= A + B) printf("Yes\n");
	else printf("No\n");

	return 0;
}
