#include <stdio.h>
#include <string.h>

#define N 1000

int sum[N];
char buffer[N];

int
main()
{
	int i;

	for (i = 0; i < N; i++) sum[i] = 0;
	while (scanf("%s", buffer), strcmp(buffer, "0") != 0)
	{
		for (i = 0; i < strlen(buffer); i++) sum[strlen(buffer) - 1 - i] += buffer[i] - '0';
		for (i = 1; i < N; i++)
		{
			sum[i] += sum[i - 1] / 10;
			sum[i - 1] %= 10;
		}
	}

	i = N - 1;
	while (sum[i] == 0) i--;
	for (; i >= 0; i--) printf("%d", sum[i]);
	printf("\n");

	return 0;
}
