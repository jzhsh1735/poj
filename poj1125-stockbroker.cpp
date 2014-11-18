#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dist[100][100];

void
floyd()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] >= 0 && dist[k][j] >= 0
                    && (dist[i][j] < 0 || dist[i][k] + dist[k][j] < dist[i][j])) dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    int find = 0, index, value;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] < 0) flag = -1;
            else if (flag >= 0) flag = max(flag, dist[i][j]);
        }
        if (flag >= 0 && (find == 0 || value > flag)) find = 1, index = i, value = flag;
    }
    if (find) cout << index + 1 << " " << value << endl;
    else cout << "disjoint" << endl;
}

int
main()
{
    while (cin >> n)
    {
        if (n == 0) break;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) dist[i][j] = -1;
        }
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (int i = 0; i < n; i++)
        {
            int m, key, value;
            cin >> m;
            while (m--)
            {
                cin >> key >> value;
                dist[i][key - 1] = value;
            }
        }
        floyd();
    }
    return 0;
}
