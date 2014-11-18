#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int
hasCommonSubstring(string &s1, string &s2, int len)
{
    unsigned long long base = 1e8+7;
    unsigned long long p = 1;
    for (int i = 0; i < len; i++) p *= base;

    vector<unsigned long long> hash;
    unsigned long long h1 = 0;
    for (int i = 0; i < len; i++) h1 = h1 * base + s1[i];
    hash.push_back(h1);
    for (int i = len; i < s1.size(); i++)
    {
        h1 = h1 * base - s1[i - len] * p + s1[i];
        hash.push_back(h1);
    }
    sort(hash.begin(), hash.end());

    unsigned long long h2 = 0;
    for (int i = 0; i < len; i++) h2 = h2 * base + s2[i];
    if (binary_search(hash.begin(), hash.end(), h2)) return 1;
    for (int i = len; i < s2.size(); i++)
    {
        h2 = h2 * base - s2[i - len] * p + s2[i];
        if (binary_search(hash.begin(), hash.end(), h2)) return 1;
    }
    return 0;
}

int
longestCommonSubstring(string &s1, string &s2)
{
    int left = 1, right = min(s1.size(), s2.size()), res = 0;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (hasCommonSubstring(s1, s2, mid))
        {
            left = mid + 1;
            res = max(res, mid);
        }
        else right = mid;
    }
    if (hasCommonSubstring(s1, s2, left)) res = max(res, left);
    return res;
}

int
main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestCommonSubstring(s1, s2) << endl;
    return 0;
}
