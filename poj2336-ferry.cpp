#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 10000000;
int c, n, t, m;
int car[2000];
int dp[2000], trip[2000];

int
main()
{
    cin >> c;
    while (c--)
    {
        cin >> n >> t >> m;
        for (int i = 1; i <= m; i++) cin >> car[i];
        dp[0] = -t;
        trip[0] = 0;
        for (int i = 1; i <= m; i++)
        {
            dp[i] = INF;
            for (int j = 1; j <= n && i - j >= 0; j++)
            {
                int temp = max(dp[i - j] + t, car[i]) + t;
                if (dp[i] > temp)
                {
                    dp[i] = temp;
                    trip[i] = trip[i - j] + 1;
                }
                else if (dp[i] == temp && trip[i] > trip[i - j] + 1)
                {
                    trip[i] = trip[i - j] + 1;
                }
            }
        }
        cout << dp[m] << " " << trip[m] << endl;
    }
    return 0;
}
