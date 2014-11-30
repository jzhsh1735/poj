#include <stdio.h>

int n, t;
int song[1000];

int
main()
{
	int i;

	scanf("%d %d", &n, &t);
	for (i = 0; i < n; i++) scanf("%d", &song[i]);

	while (t--)
	{
		int index, max = 0, temp1, temp2;
		for (i = 0; i < n; i++)
		{
			if (song[i] > max)
			{
				index = i;
				max = song[i];
			}
		}

		temp1 = song[index] / (n - 1);
		temp2 = song[index] % (n - 1);
		for (i = 0; i < n; i++)
		{
			if (i == index) song[i] = 0;
			else
			{
				song[i] += temp1;
				if (temp2 > 0)
				{
					song[i]++;
					temp2--;
				}
			}
		}

		printf("%d\n", index + 1);
	}

	return 0;
}
