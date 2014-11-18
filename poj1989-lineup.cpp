#include <iostream>
using namespace std;

int n, k;
int flag[10001];

int
main()
{
    int cow, cnt = 0, res = 0;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) flag[i] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> cow;
        if (flag[cow] == 0)
        {
            flag[cow] = 1;
            cnt++;
            if (cnt == k)
            {
                res++;
                cnt = 0;
                for (int j = 1; j <= k; j++) flag[j] = 0;
            }
        }
    }
    cout << res + 1 << endl;
    return 0;
}
