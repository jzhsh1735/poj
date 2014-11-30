#include <stdio.h>

int n;
int x[300000], v[300000];

int num[100];
long long ans;

int rank[300000], idx[300000];

struct node
{
	int front, back;
	double time, dist;
};

int len;
struct node heap[300000];

void
push(int front, int back, double time, double dist)
{
	int i;

	len++;
	for (i = len; i >= 1; i /= 2)
	{
		if (i / 2 >= 1 && (heap[i / 2].time > time || heap[i / 2].time == time && heap[i / 2].dist > dist))
		{
			heap[i].front = heap[i / 2].front; heap[i].back = heap[i / 2].back;
			heap[i].time = heap[i / 2].time; heap[i].dist = heap[i / 2].dist;
		}
		else break;
	}
	heap[i].front = front; heap[i].back = back;
	heap[i].time = time; heap[i].dist = dist;
}

void
pop()
{
	int i, j;

	for (i = 1; i * 2 < len; i = j)
	{
		j = i * 2;
		if (i * 2 + 1 < len && (heap[i * 2].time > heap[i * 2 + 1].time || heap[i * 2].time == heap[i * 2 + 1].time && heap[i * 2].dist > heap[i * 2 + 1].dist)) j = i * 2 + 1;
		if (heap[j].time < heap[len].time || heap[j].time == heap[len].time && heap[j].dist < heap[len].dist)
		{
			heap[i].front = heap[j].front; heap[i].back = heap[j].back;
			heap[i].time = heap[j].time; heap[i].dist = heap[j].dist;
		}
		else break;
	}
	heap[i].front = heap[len].front; heap[i].back = heap[len].back;
	heap[i].time = heap[len].time; heap[i].dist = heap[len].dist;
	len--;
}

int
main()
{
	int i, j, t1, t2, t3;
	double tt, td;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &x[i], &v[i]);
		rank[i] = idx[i] = i;
	}
	for (i = 0; i < 100; i++) num[i] = 0;
	ans = 0;
	for (i = n; i > 0; i--)
	{
		for (j = 0; j < v[i]; j++) ans += num[j];
		num[v[i]]++;
	}
	printf("%lld\n", ans % 1000000);

	len = 0;
	for (i = 1; i < n; i++)
	{
		if (v[i] > v[i + 1])
		{
			tt = (double)(x[i + 1] - x[i]) / (v[i] - v[i + 1]);
			td = x[i] + v[i] * tt;
			push(i + 1, i, tt, td);
		}
	}
	for (i = 0; i < 10000 && len; i++)
	{
		t1 = heap[1].back;
		t2 = heap[1].front;

		if (rank[t1] < n && idx[rank[t1] + 1] == t2)
		{
			printf("%d %d\n", t1, t2);
			pop();

			t3 = rank[t1]; rank[t1] = rank[t2]; rank[t2] = t3;
			idx[rank[t1]] = t1; idx[rank[t2]] = t2;
			if (rank[t1] < n)
			{
				t3 = idx[rank[t1] + 1];
				if (v[t1] > v[t3])
				{
					tt = (double)(x[t3] - x[t1]) / (v[t1] - v[t3]);
					td = x[t3] + v[t3] * tt;
					push(t3, t1, tt, td);
				}
			}
			if (rank[t2] > 1)
			{
				t3 = idx[rank[t2] - 1];
				if (v[t3] > v[t2])
				{
					tt = (double)(x[t2] - x[t3]) / (v[t3] - v[t2]);
					td = x[t3] + v[t3] * tt;
					push(t2, t3, tt, td);
				}
			}
		}
		else
		{
			pop();
			i--;
		}

	}

	return 0;
}
