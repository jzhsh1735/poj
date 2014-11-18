#include <iostream>
#include <algorithm>
using namespace std;

int t, w;
int apple[1001];
int dp[1001][31];

int
main()
{
    cin >> t >> w;
    for (int i = 1; i <= t; i++) cin >> apple[i];
    for (int i = 0; i <= t; i++)
    {
        for (int j = 0; j <= w; j++) dp[i][j] = 0;
    }
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j <= w && j <= i; j++)
        {
            if (j == 0) dp[i][j] = dp[i - 1][j] + ((j + 1) % 2 == apple[i] % 2? 1: 0);
            else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + ((j + 1) % 2 == apple[i] % 2? 1: 0);
        }
    }
    int res = 0;
    for (int i = 0; i <= w; i++) res = max(res, dp[t][i]);
    cout << res << endl;
    return 0;
}
