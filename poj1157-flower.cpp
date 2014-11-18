#include <iostream>
#include <algorithm>
using namespace std;

int
main()
{
    int f, v;
    int val[100][100], dp[101][101];
    cin >> f >> v;
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < v; j++) cin >> val[i][j];
    }
    for (int i = 0; i <= f; i++)
    {
        for (int j = 0; j <= v; j++) dp[i][j] = 0;
    }
    for (int i = 1; i <= f; i++) dp[i][i] = dp[i - 1][i - 1] + val[i - 1][i - 1];
    for (int i = 1; i <= f; i++)
    {
        for (int j = i + 1; j <= v; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1] + val[i - 1][j - 1], dp[i][j - 1]);
        }
    }
    cout << dp[f][v] << endl;
    return 0;
}
