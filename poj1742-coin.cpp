#include <iostream>
using namespace std;

int n, m;
int a[100], c[100];
int dp[100001], used[100001];

int
main()
{
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        dp[0] = 1;
        for (int i = 1; i <= m; i++) dp[i] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= m; j++) used[j] = 0;
            for (int j = 0; j <= m; j++)
            {
                if (dp[j] == 0 && j - a[i] >= 0 && dp[j - a[i]] && used[j - a[i]] + 1 <= c[i])
                {
                    dp[j] = 1;
                    used[j] = used[j - a[i]] + 1;
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= m; i++) res += dp[i];
        cout << res << endl;
    }
    return 0;
}
