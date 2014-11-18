#include <iostream>
#include <cstdlib>
using namespace std;

int t, n;
int fat[20001], rel[20001];

int
find(int x)
{
    if (fat[x] == 0) return x;
    int temp = fat[x];
    fat[x] = find(fat[x]);
    rel[x] += rel[temp];
    return fat[x];
}

int
main()
{
    char cmd;
    int x, y;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) fat[i] = rel[i] = 0;
        while (cin >> cmd)
        {
            if (cmd == 'E')
            {
                cin >> x;
                find(x);
                cout << rel[x] << endl;
            }
            else if (cmd == 'I')
            {
                cin >> x >> y;
                fat[x] = y;
                rel[x] = abs(x - y) % 1000;
            }
            else break;
        }
    }
    return 0;
}
