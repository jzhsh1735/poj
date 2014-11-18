#include <iostream>
using namespace std;

long long a[51][51], b[51][51];

void
down(int i, int j, int d)
{
    long long tempa = a[i][j], tempb = b[i][j] * 2;
    while (b[i + 1][d] < tempb) a[i + 1][d] *= 2, b[i + 1][d] *= 2;
    while (b[i + 1][d] > tempb) tempa *= 2, tempb *= 2;
    a[i + 1][d] += tempa;
}

long long
gcd(long long x, long long y)
{
    return y? gcd(y, x % y): x;
}

int
main()
{
    int n, m;
    char ch;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            a[i][j] = 0;
            b[i][j] = 1;
        }
    }
    a[0][0] = b[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> ch;
            if (ch == '*')
            {
                down(i, j, j);
                down(i, j, j + 1);
            }
            else
            {
                a[i + 2][j + 1] = a[i][j];
                b[i + 2][j + 1] = b[i][j];
            }
        }
    }
    long long d = gcd(a[n][m], b[n][m]);
    cout << a[n][m] / d << "/" << b[n][m] / d << endl;
    return 0;
}
