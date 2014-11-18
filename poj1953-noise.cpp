#include <iostream>
using namespace std;

int t, n;
long long dp[50];

int
main()
{
    dp[0] = 0; dp[1] = 2; dp[2] = 3;
    for (int i = 3; i < 45; i++) dp[i] = dp[i - 1] + dp[i - 2];
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        cout << "Scenario #" << i << ":" << endl;
        cout << dp[n] << endl << endl;
    }
    return 0;
}
