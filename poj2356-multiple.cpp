#include <iostream>
using namespace std;

int n;
int num[10001];
int idx[10001];

int
main()
{
    cin >> n;
    for (int i = 0; i < n; i++) idx[i] = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        sum += num[i];
        if (sum % n == 0)
        {
            cout << i << endl;
            for (int j = 1; j <= i; j++) cout << num[j] << endl;
            break;
        }
        if (idx[sum % n])
        {
            cout << i - idx[sum % n] << endl;
            for (int j = idx[sum % n] + 1; j <= i; j++) cout << num[j] << endl;
            break;
        }
        idx[sum % n] = i;
    }
    return 0;
}
