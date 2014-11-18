#include <iostream>
#include <algorithm>
using namespace std;

int k;
struct node
{
    int h, c, a;
};
struct node block[401];
int dp[40001], used[40001];

bool
compare(struct node x, struct node y)
{
    return x.a < y.a;
}

int
main()
{
    cin >> k;
    for (int i = 0; i < k; i++) cin >> block[i].h >> block[i].a >> block[i].c;
    sort(block, block + k, compare);
    dp[0] = 1;
    for (int i = 1; i <= 40000; i++) dp[i] = 0;
    int res = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j <= 40000; j++) used[j] = 0;
        for (int j = block[i].h; j <= 40000 && j <= block[i].a; j++)
        {
            if (!dp[j] && dp[j - block[i].h] && used[j - block[i].h] + 1 <= block[i].c)
            {
                dp[j] = 1;
                used[j] = used[j - block[i].h] + 1;
                res = max(res, j);
            }
        }
    }
    cout << res << endl;
    return 0;
}
