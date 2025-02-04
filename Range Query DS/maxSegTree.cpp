#include <bits/stdc++.h>
using namespace std;
/*Used to get max element fom a given range from the array*/

// Time Complexity:- O(n)
void buildSegTree(int index, int low, int high, int n, vector<int> &arr, vector<int> &segTree)
{
    // bc
    if (low == high)
    {
        segTree[index] = arr[low];
        return;
    }

    int mid = low + (high - low) / 2;
    buildSegTree(2 * index + 1, low, mid, n, arr, segTree);
    buildSegTree(2 * index + 2, mid + 1, high, n, arr, segTree);
    segTree[index] = max(segTree[2 * index + 1], segTree[2 * index + 2]);
}

// Time Complexity:- O(logn)
int query(int index, int l, int r, int low, int high, int n, vector<int> &segTree)
{
    // 3 cases
    //  1--> node lies completely in the range => complete contri.
    //  2--> range lies completely outside the range => no contri.
    //  3--> range partially/completely overlap => split recursively

    // bc
    if (l <= low && high <= r)
    {
        return segTree[index];
    }
    if (low > r || high < l)
    {
        return INT_MIN;
    }

    int mid = low + (high - low) / 2;
    int left = query(2 * index + 1, l, r, low, mid, n, segTree);
    int right = query(2 * index + 2, l, r, mid + 1, high, n, segTree);
    return max(left, right);
}

// for updation
void update(int index, int low, int high, int n, vector<int> &segTree, int pos, int val)
{
    // bc
    if (low == high)
    {
        segTree[index] = val;
        return;
    }

    int mid = low + (high - low) / 2;
    if (pos <= mid)
    {
        update(2 * index + 1, low, mid, n, segTree, pos, val);
    }
    else
    {
        update(2 * index + 2, mid + 1, high, n, segTree, pos, val);
    }
    segTree[index] = max(segTree[2 * index + 1], segTree[2 * index + 2]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> segTree(4 * n); // for worst case scenario
    buildSegTree(0, 0, n - 1, n, arr, segTree);
    cout << "Segment Tree Built Successfully!" << endl;
    while (true)
    {
        cout << "Enter range for query(-1 to exit):" << endl;
        int l, r;
        cin >> l >> r;
        if (l == -1 || r == -1)
        {
            cout << "Exiting the program" << endl;
            break;
        }
        cout << "Max Element in that range is: " << query(0, l, r, 0, n - 1, n, segTree) << endl;
    }
    return 0;
}