#include <iostream>
using namespace std;

int cash, n;
int nk[10], Dk[10];
int dp[100001], used[100001];

void
solve()
{
    for (int i = 0; i <= cash; i++) dp[i] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= cash; j++) used[j] = 0;
        for (int j = 0; j <= cash; j++)
        {
            if (j - Dk[i] >= 0 && used[j - Dk[i]] + 1 <= nk[i] && dp[j] < dp[j - Dk[i]] + Dk[i])
            {
                dp[j] = dp[j - Dk[i]] + Dk[i];
                used[j] = used[j - Dk[i]] + 1;
            }
        }
    }
    cout << dp[cash] << endl;
}

int
main()
{
    while (cin >> cash >> n)
    {
        for (int i = 0; i < n; i++) cin >> nk[i] >> Dk[i];
        solve();
    }
    return 0;
}
