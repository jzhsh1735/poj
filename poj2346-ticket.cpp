#include <iostream>
using namespace std;

int n;
int dp[6][50];

int
main()
{
    cin >> n;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 50; j++) dp[i][j] = 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j <= i * 9; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (j - k >= 0) dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= n / 2 * 9; i++) res += dp[n / 2][i] * dp[n / 2][i];
    cout << res << endl;
    return 0;
}
