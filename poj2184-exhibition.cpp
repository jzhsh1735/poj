#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 100000;
int n;
int w[100], v[100];
int dp[200001];

int
main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    for (int i = 0; i <= 200000; i++) dp[i] = -INF;
    dp[100000] = 0;
    for (int i = 0; i < n; i++)
    {
        if (w[i] > 0)
        {
            for (int j = 200000; j >= w[i]; j--) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
        else
        {
            for (int j = 0; j <= 200000 + w[i]; j++) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    int res = 0;
    for (int i = 100000; i <= 200000; i++)
    {
        if (dp[i] >= 0) res = max(res, dp[i] + i - 100000);
    }
    cout << res << endl;
    return 0;
}
