#include <iostream>
#include <cstring>
using namespace std;

int n;
char str[3][401];
int dp[201][201];

int
main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> str[0] >> str[1] >> str[2];
        int len1 = strlen(str[0]), len2 = strlen(str[1]);
        for (int i1 = 0; i1 <= len1; i1++)
        {
            for (int i2 = 0; i2 <= len2; i2++) dp[i1][i2] = 0;
        }
        dp[0][0] = 1;
        for (int i3 = 1; i3 <= len1 + len2; i3++)
        {
            for (int i1 = 0; i3 - i1 >= 0 && i1 <= len1; i1++)
            {
                int i2 = i3 - i1;
                if (i1 > 0 && dp[i1 - 1][i2] && str[0][i1 - 1] == str[2][i3 - 1]
                    || i2 > 0 && dp[i1][i2 - 1] && str[1][i2 - 1] == str[2][i3 - 1])
                {
                    dp[i1][i2] = 1;
                }
            }
        }
        cout << "Data set " << i << ": " << (dp[len1][len2]? "yes": "no") << endl;
    }
    return 0;
}
