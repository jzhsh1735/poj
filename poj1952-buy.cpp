#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[5001];
int len[5001], cnt[5001];

void
longestSubsequence()
{
    int maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        len[i] = 0;
        for (int j = 0; j < i; j++)
        {
            if (p[j] > p[i]) len[i] = max(len[i], len[j]);
        }
        len[i]++;
        maxlen = max(maxlen, len[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cnt[i] = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (p[j] > p[i] && len[j] + 1 == len[i])
            {
                int flag = 1;
                for (int k = j + 1; k < i; k++)
                {
                    if (p[j] == p[k])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag) cnt[i] += cnt[j];
            }
        }
        if (cnt[i] == 0) cnt[i] = 1;
    }
    cout << maxlen - 1 << " " << cnt[n - 1] << endl;
}

int
main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    p[n++] = -1;
    longestSubsequence();
    return 0;
}
