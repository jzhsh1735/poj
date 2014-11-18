#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1000][1000];

int
main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int len1 = str1.size(), len2 = str2.size();
        for (int i = 0; i <= len1; i++)
        {
            for (int j = 0; j <= len2; j++) dp[i][j] = 0;
        }
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                dp[i][j] = str1[i - 1] == str2[j - 1]? dp[i - 1][j - 1] + 1: max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[len1][len2] << endl;
    }
    return 0;
}
