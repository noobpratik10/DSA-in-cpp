#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Find thee subsequence of a string

void subsequence(string str, string output, int index, vector<string> &ans)
{
    // Base case
    if (index >= str.length())
    {
        ans.push_back(output);
        return;
    }

    // Recursive call
    // exclude
    subsequence(str, output, index + 1, ans);

    // include
    char element = str[index];
    output.push_back(element);
    subsequence(str, output, index + 1, ans);
}

int main()
{
    string str;
    cin >> str;

    cout << "Entered string is: " << endl;

    vector<string> ans;
    string output;
    int index = 0;

    subsequence(str, output, index, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}