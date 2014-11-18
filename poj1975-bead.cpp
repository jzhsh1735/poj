#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 10000;
int t, n, m;
int heavy[100][100], light[100][100];

void
floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                heavy[i][j] = min(heavy[i][j], heavy[i][k] + heavy[k][j]);
                light[i][j] = min(light[i][j], light[i][k] + light[k][j]);
            }
        }
    }
}

int
main()
{
    int x, y;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) heavy[i][j] = light[i][j] = INF;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            heavy[x][y] = light[y][x] = 1;
        }
        floyd();
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int cnt_heavy = 0, cnt_light = 0;
            for (int j = 1; j <= n; j++)
            {
                if (heavy[i][j] < INF) cnt_heavy++;
                if (light[i][j] < INF) cnt_light++;
            }
            if (cnt_heavy > n / 2 || cnt_light > n / 2) res++;
        }
        cout << res << endl;
    }
    return 0;
}
