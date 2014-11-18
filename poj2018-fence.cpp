#include <iostream>
#include <algorithm>
using namespace std;

int n, f;
double cow[100001], sum[100001];

int
check(double value)
{
    double cur = sum[f - 1] - value * (f - 1);
    for (int i = f; i <= n; i++)
    {
        cur = cur + cow[i] - value;
        cur = max(cur, sum[i] - sum[i - f] - value * f);
        if (cur > -1e-6) return 1;
    }
    return 0;
}

int
main()
{
    double left = 3e8, right = 0, mid;
    cin >> n >> f;
    cow[0] = sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> cow[i];
        sum[i] = sum[i - 1] + cow[i];
        left = min(left, cow[i]);
        right = max(right, cow[i]);
    }
    while (right - left > 1e-6)
    {
        mid = (left + right) / 2;
        if (check(mid)) left = mid;
        else right = mid;
    }
    cout << (int)(right * 1000) << endl;
    return 0;
}
