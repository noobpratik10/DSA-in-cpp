#include <bits/stdc++.h>
using namespace std;

/*
-- This Algorithm is called KMP Algorithm which has TC=O(m+n)
-- This makes use of finction LPS-Longest Prefix Suffix
-- LPS Array tells us at each index the longest length of prefix
    which is has matching suffix till that index.
*/

vector<int> getLPS(string &s)
{
    int n = s.length();
    vector<int> ans(n, 0);
    int pre = 0;
    int suf = 1;
    while (suf < n)
    {
        if (s[pre] == s[suf])
        {
            ans[suf] = pre + 1;
            pre++;
            suf++;
        }
        else
        {
            if (pre == 0)
            {
                ans[suf] = 0;
                suf++;
            }
            else
            {
                pre = ans[pre - 1];
            }
        }
    }
    return ans;
}

vector<int> KMPAlgo(string &s, string &pat)
{
    vector<int> lps = getLPS(pat);
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < s.length())
    {
        if (s[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j > 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == pat.size())
        {
            ans.push_back(i - pat.size());
        }
    }
    return ans;
}

int main()
{
    cout << "Enter the string to be searched:" << endl;
    string s;
    cin >> s;
    cout << "Enter the pattern to be searched" << endl;
    string pat;
    cin >> pat;
    vector<int> ans = KMPAlgo(s, pat);
    if (ans.empty())
    {
        cout << "Pattern not present in the string." << endl;
    }
    else
    {
        cout << "Pattern is present in the string at following indices:" << endl;
        for (auto i : ans)
        {
            cout << i << " ";
        }
    }
    return 0;
}