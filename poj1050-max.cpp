#include <iostream>
#include <algorithm>
using namespace std;

int
maxSubarray(int *array, int len)
{
    int res = -128, dp = 0;
    for (int i = 0; i < len; i++)
    {
        dp = max(dp + array[i], array[i]);
        res = max(res, dp);
    }
    return res;
}

int
main()
{
    int n;
    int m[100][100];
    int row[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cin >> m[i][j];
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) row[j] = 0;
        for (int j = 0; i + j < n; j++)
        {
            for (int k = 0; k < n; k++) row[k] += m[i + j][k];
            res = max(res, maxSubarray(row, n));
        }
    }
    cout << res << endl;
    return 0;
}
