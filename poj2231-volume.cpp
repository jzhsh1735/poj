#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long loc[10000];

int
main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> loc[i];
    sort(loc, loc + n);
    long long res = 0, sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += (loc[i] - loc[i - 1]) * i;
        res += sum;
    }
    cout << res * 2 << endl;
    return 0;
}
