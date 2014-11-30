#include <stdio.h>

#define N 20000

struct node
{
	int val;
	struct node* nxt;
};

int t, n, ncnt, root, ans;
struct node *ehead[N], edge[N], *qhead[N], query[N];
int deg[N], fat[N], visit[N];

int
find(int x)
{
	if (fat[x] == -1) return x;
	else return fat[x] = find(fat[x]);
}

void
lca(int x)
{
	struct node *p;

	visit[x] = 1;
	p = ehead[x];
	while (p != NULL)
	{
		lca(p->val);
		fat[p->val] = x;
		p = p->nxt;
	}
	p = qhead[x];
	while (p != NULL)
	{
		if (visit[p->val]) ans = find(p->val);
		p = p->nxt;
	}
}

int
main()
{
	int i, j;
	int t1, t2;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++) deg[i] = visit[i] = 0;
		for (i = 1; i <= n; i++) ehead[i] = qhead[i] = NULL;
		for (i = 1; i <= n; i++) fat[i] = -1;
		ncnt = 0;
		for (i = 0; i < n - 1; i++)
		{
			scanf("%d %d", &t1, &t2);
			deg[t2]++;
			edge[ncnt].val = t2;
			edge[ncnt].nxt = ehead[t1];
			ehead[t1] = edge + ncnt;
			ncnt++;
		}
		scanf("%d %d", &t1, &t2);
		query[0].val = t2;
		query[0].nxt = qhead[t1];
		qhead[t1] = query;
		query[1].val = t1;
		query[1].nxt = qhead[t2];
		qhead[t2] = query + 1;
		for (i = 1; i <= n; i++)
		{
			if (deg[i] == 0) root = i;
		}
		lca(root);
		printf("%d\n", ans);
	}

	return 0;
}
