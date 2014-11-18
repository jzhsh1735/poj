#include <iostream>
#include <algorithm>
using namespace std;

int n, w, h, s, t;
int tree[101][101], dp[101][101];

int
main()
{
    int x, y;
    while (cin >> n)
    {
        if (n == 0) break;
        cin >> w >> h;
        for (int i = 1; i <= w; i++)
        {
            for (int j = 1; j <= h; j++) tree[i][j] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            tree[x][y] = 1;
        }
        cin >> s >> t;
        for (int i = 0; i <= w; i++)
        {
            for (int j = 0; j <= h; j++) dp[i][j] = 0;
        }
        for (int i = 1; i <= w; i++)
        {
            for (int j = 1; j <= h; j++) dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + tree[i][j];
        }
        int res = 0;
        for (int i = s; i <= w; i++)
        {
            for (int j = t; j <= h; j++) res = max(res, dp[i][j] - dp[i - s][j] - dp[i][j - t] + dp[i - s][j - t]);
        }
        cout << res << endl;
    }
    return 0;
}
