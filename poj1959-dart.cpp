#include <iostream>
using namespace std;

int dart[63] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
    2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,
    3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,
    25,50};

int
main()
{
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        int res = 0;
        for (int a = 0; a < 63; a++)
        {
            for (int b = a; b < 63; b++)
            {
                for (int c = b; c < 63; c++)
                {
                    if (dart[a] + dart[b] + dart[c] == n) res++;
                }
            }
        }
        cout << "Scenario #" << i << ":" << endl;
        cout << res << endl << endl;
    }
    return 0;
}
