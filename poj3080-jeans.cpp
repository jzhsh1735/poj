#include <iostream>
#include <vector>
#include <string>
using namespace std;

void
getNext(string &str, vector<int> &next)
{
    next[0] = 0;
    for (int i = 1, j = 0; i < str.size(); i++)
    {
        while (j > 0 && str[i] != str[j]) j = next[j - 1];
        if (str[i] == str[j]) j++;
        next[i] = j;
    }
}

int
isSubstring(string &str, string &target)
{
    vector<int> next(target.size(), 0);
    getNext(target, next);
    for (int i = 0, j = 0; i < str.size(); i++)
    {
        while (j > 0 && str[i] != target[j]) j = next[j - 1];
        if (str[i] == target[j]) j++;
        if (j == target.size()) return 1;
    }
    return 0;
}

string
longestCommonSubstring(vector<string> &s)
{
    string res;
    for (int len = 3; len <= s[0].size(); len++)
    {
        for (int head = 0; head + len - 1 < s[0].size(); head++)
        {
            string target = s[0].substr(head, len);
            int cnt = 1;
            for (int i = 1; i < s.size(); i++)
            {
                if (isSubstring(s[i], target)) cnt++;
                else break;
            }
            if (cnt == s.size() && (res.size() < target.size() || res.size() == target.size() && res > target)) res = target;
        }
    }
    return res;
}

int
main()
{
    int t, n;
    string str;
    cin >> t;
    while (t--)
    {
        vector<string> s;
        cin >> n;
        while (n--)
        {
            cin >> str;
            s.push_back(str);
        }
        string res = longestCommonSubstring(s);
        cout << (res.empty()? "no significant commonalities": res) << endl;
    }
    return 0;
}
