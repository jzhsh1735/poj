#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
int L[3], C[3];
int n, s, t;
int dist[10001];
int dp[10001];

int
fee(int x, int y)
{
    int d = dist[y] - dist[x];
    for (int i = 0; i < 3; i++)
    {
        if (d <= L[i]) return C[i];
    }
    return 0;
}

int
main()
{
    for (int i = 0; i < 3; i++) cin >> L[i];
    for (int i = 0; i < 3; i++) cin >> C[i];
    cin >> n;
    cin >> s >> t;
    if (s > t) swap(s, t);
    dist[1] = 0;
    for (int i = 2; i <= n; i++) cin >> dist[i];
    for (int i = s; i <= t; i++) dp[i] = INF;
    dp[s] = 0;
    for (int i = s; i <= t; i++)
    {
        for (int j = i + 1; dist[j] - dist[i] <= L[2] && j <= t; j++)
        {
            dp[j] = min(dp[j], dp[i] + fee(i, j));
        }
    }
    cout << dp[t] << endl;
    return 0;
}
