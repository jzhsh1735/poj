#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 10000;
char str[10][30];
int len[10];
int next[30];
int pre[10][10];
int dp[1 << 10][10];

void
getNext(int s)
{
    next[0] = 0;
    for (int i = 1, j = 0; i < len[s]; i++)
    {
        while (j > 0 && str[s][i] != str[s][j]) j = next[j - 1];
        if (str[s][i] == str[s][j]) j++;
        next[i] = j;
    }
}

void
kmp(int s1, int s2)
{
    for (int i = 0, j = 0; i < len[s1]; i++)
    {
        while (j > 0 && str[s1][i] != str[s2][j]) j = next[j - 1];
        if (str[s1][i] == str[s2][j]) j++;
        pre[s1][s2] = j;
        if (j == len[s2]) j = next[j - 1];
    }
}

int
main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
            len[i] = strlen(str[i]);
        }
        for (int i = 0; i < n; i++)
        {
            getNext(i);
            for (int j = 0; j < n; j++) kmp(j, i);
        }
        for (int i = 0; i < (1 << n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = INF;
                if (i & (1 << j))
                {
                    if (i == (1 << j)) dp[i][j] = len[j];
                    else
                    {
                        for (int k = 0; k < n; k++)
                        {
                            if (j != k && (i & (1 << k)))
                            {
                                dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + len[j] - pre[k][j]);
                            }
                        }
                    }
                }
            }
        }
        int res = INF;
        for (int i = 0; i < n; i++) res = min(res, dp[(1 << n) - 1][i]);
        cout << res << endl;
    }
    return 0;
}
