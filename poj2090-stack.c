#include <stdio.h>
#include <stdlib.h>

int n;
int orig_card[1000];
int sort_card[1000];
int stack[2][1000];
int top[2];
int ans[1000];

int
compare(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

int
dfs(int in, int out)
{
	int i, j, k;

	if (out == n) return 1;

	if (in < n && orig_card[in] == sort_card[out])
	{
		ans[in + out] = 1;
		ans[in + out + 1] = -1;

		return dfs(in + 1, out + 1);
	}

	for (i = 0; i < 2; i++)
	{
		if (top[i] >= 0 && stack[i][top[i]] == sort_card[out])
		{
			j = stack[i][top[i]--];
			ans[in + out] = - (i + 1);
			k = dfs(in, out + 1);
			stack[i][++top[i]] = j;

			return k;
		}
	}

	if (in < n)
	{
		for (i = 0; i < 2; i++)
		{
			if (top[i] < 0 || orig_card[in] <= stack[i][top[i]])
			{
				stack[i][++top[i]] = orig_card[in];
				ans[in + out] = i + 1;
				if (dfs(in + 1, out)) return 1;
				top[i]--;
			}
		}
	}

	return 0;
}

int
main()
{
	int i, cnt = 0;

	while (scanf("%d", &n), n)
	{
		for (i = n - 1; i >= 0; i--)
		{
			scanf("%d", &orig_card[i]);
			sort_card[i] = orig_card[i];
		}
		qsort(sort_card, n, sizeof(int), compare);

		cnt++;
		printf("#%d\n", cnt);
		top[0] = top[1] = -1;
		if (dfs(0, 0))
		{
			for (i = 0; i < 2 * n; i++)
			{
				if (ans[i] == 1) printf("push 1\n");
				else if (ans[i] == -1) printf("pop 1\n");
				else if (ans[i] == 2) printf("push 2\n");
				else printf("pop 2\n");
			}
		}
		else printf("impossible\n");
	}

	return 0;
}
