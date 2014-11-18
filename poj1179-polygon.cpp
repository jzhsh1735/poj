#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 10000000;
int n;
char oper[50];
long long num[50];
long long dpmax[50][51], dpmin[50][51];

int
main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> oper[i] >> num[i];
    for (int i = 0; i < n; i++) dpmax[i][1] = dpmin[i][1] = num[i];
    for (int len = 2; len <= n; len++)
    {
        for (int head = 0; head < n; head++)
        {
            dpmax[head][len] = -INF;
            dpmin[head][len] = INF;
            for (int i = 1; i < len; i++)
            {
                if (oper[(head + i) % n] == 't')
                {
                    dpmax[head][len] = max(dpmax[head][len], dpmax[head][i] + dpmax[(head + i) % n][len - i]);
                    dpmin[head][len] = min(dpmin[head][len], dpmin[head][i] + dpmin[(head + i) % n][len - i]);
                }
                else
                {
                    dpmax[head][len] = max(dpmax[head][len], dpmax[head][i] * dpmax[(head + i) % n][len - i]);
                    dpmax[head][len] = max(dpmax[head][len], dpmin[head][i] * dpmin[(head + i) % n][len - i]);
                    dpmax[head][len] = max(dpmax[head][len], dpmax[head][i] * dpmin[(head + i) % n][len - i]);
                    dpmax[head][len] = max(dpmax[head][len], dpmin[head][i] * dpmax[(head + i) % n][len - i]);
                    dpmin[head][len] = min(dpmin[head][len], dpmin[head][i] * dpmin[(head + i) % n][len - i]);
                    dpmin[head][len] = min(dpmin[head][len], dpmax[head][i] * dpmin[(head + i) % n][len - i]);
                    dpmin[head][len] = min(dpmin[head][len], dpmin[head][i] * dpmax[(head + i) % n][len - i]);
                    dpmin[head][len] = min(dpmin[head][len], dpmax[head][i] * dpmax[(head + i) % n][len - i]);
                }
            }
        }
    }
    long long res = -INF;
    vector<int> edge;
    for (int i = 0; i < n; i++)
    {
        if (dpmax[i][n] > res)
        {
            res = dpmax[i][n];
            edge.clear();
        }
        if (dpmax[i][n] == res) edge.push_back(i);
    }
    cout << res << endl;
    for (int i = 0; i < edge.size(); i++) cout << edge[i] + 1 << " ";
    cout << endl;
    return 0;
}
