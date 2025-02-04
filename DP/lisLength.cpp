// Give length of the longest increasing ssubsequence in the array

#include <bits/stdc++.h>
using namespace std;
int solve1(int index, int prevInd, int &n, vector<int> &arr,
           vector<vector<int>> &dp1)
{
    if (index >= n)
        return 0;
    if (dp1[index][prevInd + 1] != -1)
        return dp1[index][prevInd + 1];

    int ans = 0;
    if (prevInd == -1 || arr[index] > arr[prevInd])
        ans = max(ans, 1 + solve1(index + 1, index, n, arr, dp1));
    ans = max(ans, 0 + solve1(index + 1, prevInd, n, arr, dp1));
    return dp1[index][prevInd + 1] = ans;
}

int solve2(int &n, vector<int> &arr)
{
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int solve3(int &n, vector<int> &arr)
{
    vector<int> subLen;
    for (int i = 0; i < arr.size(); i++)
    {
        if (subLen.empty() || subLen.back() < arr[i])
            subLen.push_back(arr[i]);
        else
        {
            int idx = lower_bound(subLen.begin(), subLen.end(), arr[i]) - subLen.begin();
            subLen[idx] = arr[i];
        }
    }
    return subLen.size();
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> dp1(n + 1, vector<int>(n + 2, -1));
    cout << solve1(0, -1, n, arr, dp1) << endl;

    cout << solve2(n, arr) << endl;

    cout << solve3(n, arr) << endl;
    return 0;
}