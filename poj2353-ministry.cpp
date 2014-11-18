#include <cstdio>
using namespace std;

int m, n;
int fee[100][500];
long long dp[500];
int path[100][500];

void
out(int x, int y)
{
    if (x != 0)
    {
        if (path[x][y] == 0) out(x - 1, y);
        if (path[x][y] == -1) out(x, y - 1);
        if (path[x][y] == 1) out(x, y + 1);
    }
    printf("%d\n", y + 1);
}

int
main()
{
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) scanf("%d", &fee[i][j]);
    }
    for (int i = 0; i < n; i++) dp[i] = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[j] += fee[i][j];
            path[i][j] = 0;
        }
        for (int j = 1; j < n; j++)
        {
            if (dp[j] > dp[j - 1] + fee[i][j])
            {
                dp[j] = dp[j - 1] + fee[i][j];
                path[i][j] = -1;
            }
        }
        for (int j = n - 2; j >= 0; j--)
        {
            if (dp[j] > dp[j + 1] + fee[i][j])
            {
                dp[j] = dp[j + 1] + fee[i][j];
                path[i][j] = 1;
            }
        }
    }
    long long res = dp[0];
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (dp[i] < res)
        {
            res = dp[i];
            idx = i;
        }
    }
    out(m - 1, idx);
    return 0;
}
