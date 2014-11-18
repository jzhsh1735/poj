#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2100000;
int dp[MAX];

int
nextState(int state, int num)
{
    int res = state;
    for (int i = 1; i * num <= 20; i++)
    {
        res |= 1 << (i * num);
        for (int j = 2; j <= 20; j++)
        {
            if ((state & (1 << j)) > 0 && i * num + j <= 20) res |= 1 << (i * num + j);
        }
    }
    return res;
}

int
solve(int state)
{
    if (dp[state]) return dp[state];
    for (int i = 2; i <= 20; i++)
    {
        if ((state & (1 << i)) == 0)
        {
            if (solve(nextState(state, i)) > 0)
            {
                dp[state] = -1;
                return -1;
            }
        }
    }
    dp[state] = 1;
    return 1;
}

int
main()
{
    for (int i = 0; i < MAX; i++) dp[i] = 0;
    int t = 0, n, m;
    while (cin >> n)
    {
        if (n == 0) break;
        int state = 0x1fffff;
        for (int i = 0; i < n; i++)
        {
            cin >> m;
            state -= (1 << m);
        }
        vector<int> res;
        for (int i = 2; i <= 20; i++)
        {
            if ((state & (1 << i)) == 0)
            {
                if (solve(nextState(state, i)) > 0) res.push_back(i);
            }
        }
        cout << "Test Case #" << ++t << endl;
        if (res.empty()) cout << "There's no winning move." << endl;
        else
        {
            cout << "The winning moves are:";
            for (int i = 0; i < res.size(); i++) cout << " " << res[i];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
