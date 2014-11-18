#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct rect
{
    int w, h;
};
int top;
struct rect sta[50002];

int
main()
{
    int w, h, sum;
    while (cin >> n)
    {
        if (n < 0) break;
        top = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> w >> h;
            sum = 0;
            while (top && sta[top].h >= h)
            {
                sum += sta[top].w;
                res = max(res, sum * sta[top].h);
                top--;
            }
            sum += w;
            top++;
            sta[top].w = sum;
            sta[top].h = h;
        }
        sum = 0;
        while (top)
        {
            sum += sta[top].w;
            res = max(res, sum * sta[top].h);
            top--;
        }
        cout << res << endl;
    }
    return 0;
}
