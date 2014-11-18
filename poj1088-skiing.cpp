#include <iostream>
#include <algorithm>
using namespace std;

int r, c;
int h[100][100];
int dp[100][100];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int
solve(int x, int y)
{
    if (dp[x][y]) return dp[x][y];
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && h[x][y] < h[nx][ny]) res = max(res, solve(nx, ny));
    }
    res++;
    dp[x][y] = res;
    return res;
}

int
main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) cin >> h[i][j];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) dp[i][j] = 0;
    }
    int res = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) res = max(res, solve(i, j));
    }
    cout << res << endl;
    return 0;
}
