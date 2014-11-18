#include <iostream>
using namespace std;

int c, n, m;
double dp[2][101];

int
main()
{
    while (cin >> c)
    {
        if (c == 0) break;
        cin >> n >> m;
        if (m > c || m > n || (m + n) % 2)
        {
            cout << "0.000" << endl;
            continue;
        }
        if (n > 1000) n = (n % 2? 1001: 1000);
        for (int i = 0; i <= c; i++) dp[0][i] = dp[1][i] = 0;
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= i && j <= c; j++)
            {
                dp[i % 2][j] = 0;
                if (j > 0)
                {
                    dp[i % 2][j] += (c - j + 1) * dp[(i - 1) % 2][j - 1] / c;
                }
                if (j < i && j < c)
                {
                    dp[i % 2][j] += (j + 1) * dp[(i - 1) % 2][j + 1] / c;
                }
            }
        }
        cout.precision(3);
        cout << fixed << dp[n % 2][m] << endl;
    }
    return 0;
}
