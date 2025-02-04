#include <bits/stdc++.h>
using namespace std;
class Compare
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        // // ascending
        // if (a.first == b.first)
        // {
        //     return a.second < a.second;
        // }
        // return a.first < a.first;

        // // descending
        // if (a.first == b.first)
        // {
        //     return a.second > a.second;
        // }
        // return a.first > a.first;

        // // ascending --second parameter
        // return a.second<b.second

        // descending second parameter
        return a.second > b.second;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // ascending sort
    sort(nums.begin(), nums.end());
    // descending sort
    sort(nums.begin(), nums.end(), greater<int>());

    // custom sort
    int n;
    cin >> n;

    vector<pair<int, int>> nums2;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        nums2.push_back(make_pair(x, y));
    }
    Compare cmp;
    sort(nums2.begin(), nums2.end(), cmp);

    return 0;
}