#include <iostream>
using namespace std;

int n, b, y, d;
int w[10], v[10];
int dp[100000];

int
main()
{
    cin >> n;
    while (n--)
    {
        cin >> b >> y >> d;
        for (int i = 0; i < d; i++)
        {
            cin >> w[i] >> v[i];
            w[i] /= 1000;
        }
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j <= b / 1000; j++) dp[j] = 0;
            for (int j = 0; j < d; j++)
            {
                for (int k = 0; k <= b / 1000; k++)
                {
                    if (k - w[j] >= 0) dp[k] = max(dp[k], dp[k - w[j]] + v[j]);
                }
            }
            b += dp[b / 1000];
        }
        cout << b << endl;
    }
    return 0;
}
