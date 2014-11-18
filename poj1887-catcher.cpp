#include <iostream>
#include <algorithm>
using namespace std;

int n;
int data[100001], dp[100001];

int
find(int x, int len)
{
    int left = 0, right = len;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (x >= dp[mid]) left = mid + 1;
        else right = mid;
    }
    return left;
}

int
longestSubsequence()
{
    int len = 0, res = 0;
    dp[0] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (data[i] >= dp[len])
        {
            dp[++len] = data[i];
            res = max(res, len);
        }
        else
        {
            int index = find(data[i], len);
            dp[index] = data[i];
        }
    }
    return res;
}

int
main()
{
    for (int t = 1; ; t++)
    {
        n = 0;
        while (cin >> data[n])
        {
            if (data[n] == -1) break;
            n++;
        }
        if (n == 0) break;
        cout << "Test #" << t << ":" << endl;
        cout << "  maximum possible interceptions: " << longestSubsequence() << endl << endl;
    }
    return 0;
}
