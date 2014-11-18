#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int move[100], lost[100];
double dp[100][100];

int
main()
{
    int n, m, t;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> m >> t;
        move[0] = lost[0] = 0;
        for (int i = 1; i <= m; i++)
        {
            cin >> s;
            if (s == "L") move[i] = 0, lost[i] = 1;
            else move[i] = atoi(s.c_str()), lost[i] = 0;
        }
        move[m + 1] = lost[m + 1] = 0;
        move[m + 2] = -1; lost[m + 2] = 0;
        for (int i = 0; i <= t; i++)
        {
            for (int j = 0; j <= m + 1; j++) dp[i][j] = 0;
        }
        dp[0][0] = 1;
        double res = 0;
        for (int i = 0; i <= t; i++)
        {
            res += dp[i][m + 1];
            for (int j = 0; j <= m; j++)
            {
                if (lost[j + 1]) dp[i + 2][j + 1] += dp[i][j] / 2;
                else
                {
                    int next = j + 1 + move[j + 1];
                    if (next < 0) next = 0;
                    if (next > m + 1) next = m + 1;
                    dp[i + 1][next] += dp[i][j] / 2;
                }
                if (lost[j + 2]) dp[i + 2][j + 2] += dp[i][j] / 2;
                else
                {
                    int next = j + 2 + move[j + 2];
                    if (next < 0) next = 0;
                    if (next > m + 1) next = m + 1;
                    dp[i + 1][next] += dp[i][j] / 2;
                }
            }
        }
        cout.precision(4);
        cout << fixed;
        if (res == 0.5) cout << "Push. " << res << endl;
        else if (res > 0.5) cout << "Bet for. " << res << endl;
        else cout << "Bet against. " << res << endl;
    }
    return 0;
}
