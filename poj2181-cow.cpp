#include <iostream>
#include <algorithm>
using namespace std;

int p;
int jump[150001];
int dp[2][2];

int
main()
{
    cin >> p;
    for (int i = 1; i <= p; i++) cin >> jump[i];
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= p; i++)
    {
        dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] + jump[i]);
        dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] - jump[i]);
    }
    cout << dp[p % 2][0] << endl;
    return 0;
}
