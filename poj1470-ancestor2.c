#include <stdio.h>

#define N 1000
#define M 1000000

struct node
{
	int idx, val;
	struct node* nxt;
};

int n, ncnt, q, qcnt, root;
struct node *ehead[N], edge[N], *qhead[N], query[M];
int deg[N], fat[N], visit[N], anc[M], ans[N];

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
		if (visit[p->val]) anc[p->idx] = find(p->val);
		p = p->nxt;
	}
}

int
main()
{
	int i, j;
	int t1, t2, t3;

	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++) deg[i] = visit[i] = ans[i] = 0;
		for (i = 1; i <= n; i++) ehead[i] = qhead[i] = NULL;
		for (i = 1; i <= n; i++) fat[i] = -1;
		ncnt = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &t1);
			while (getchar() != '(');
			scanf("%d", &t2);
			while (getchar() != ')');
			for (j = 0; j < t2; j++)
			{
				scanf("%d", &t3);
				deg[t3]++;
				edge[ncnt].val = t3;
				edge[ncnt].nxt = ehead[t1];
				ehead[t1] = edge + ncnt;
				ncnt++;
			}
		}
		scanf("%d", &q);
		qcnt = 0;
		for (i = 0; i < q; i++)
		{
			while (getchar() != '(');
			scanf("%d %d", &t1, &t2);
			while (getchar() != ')');
			query[qcnt].idx = i;
			query[qcnt].val = t2;
			query[qcnt].nxt = qhead[t1];
			qhead[t1] = query + qcnt;
			qcnt++;
			query[qcnt].idx = i;
			query[qcnt].val = t1;
			query[qcnt].nxt = qhead[t2];
			qhead[t2] = query + qcnt;
			qcnt++;
		}
		for (i = 1; i <= n; i++)
		{
			if (deg[i] == 0) root = i;
		}
		lca(root);
		for (i = 0; i < q; i++) ans[anc[i]]++;
		for (i = 1; i <= n; i++)
		{
			if (ans[i]) printf("%d:%d\n", i, ans[i]);
		}
	}

	return 0;
}
