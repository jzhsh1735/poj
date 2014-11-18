#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct node
{
    int p, d;
};
struct node data[10000];
int hash[10001];

bool
compare(struct node x, struct node y)
{
    return (x.p > y.p || x.p == y.p && x.d < y.d);
}

int
main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++) cin >> data[i].p >> data[i].d;
        sort(data, data + n, compare);
        for (int i = 0; i <= 10000; i++) hash[i] = 0;
        for (int i = 0; i < n; i++)
        {
            if (hash[data[i].d] == 0) hash[data[i].d] = data[i].p;
            else
            {
                for (int j = data[i].d; j >= 1; j--)
                {
                    if (hash[j] == 0)
                    {
                        hash[j] = data[i].p;
                        break;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= 10000; i++) res += hash[i];
        cout << res << endl;
    }
    return 0;
}
