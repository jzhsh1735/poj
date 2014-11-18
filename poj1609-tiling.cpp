#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct node
{
    int l, m;
};
struct node data[10000];
int dp[10001];

bool
compare(struct node x, struct node y)
{
    return (x.l < y.l || x.l == y.l && x.m < y.m);
}

int
main()
{
    while (cin >> n)
    {
        if (n == 0) break;
        for (int i = 0; i < n; i++) cin >> data[i].l >> data[i].m;
        sort(data, data + n, compare);
        for (int i = 0; i <= n; i++) dp[i] = 0;
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (data[i - 1].m >= data[j - 1].m) dp[i] = max(dp[i], dp[j]);
            }
            dp[i]++;
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }
    cout << "*" << endl;
    return 0;
}
