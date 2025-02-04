#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
    /*
    1)biary search
    2)max
    3)min
    4)sort

    */

    array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    /*this sort is based on intro sort
        its a combination of three sorts=insertion, quick, heap
    */
    sort(arr.begin(), arr.end());

    cout << "finding 6->" << binary_search(arr.begin(), arr.end(), 6);

    cout << "upper bound" << upper_bound(arr.begin(), arr.end(), 6) - arr.begin() << endl;
    cout << "lower bound" << lower_bound(arr.begin(), arr.end(), 6) - arr.begin() << endl;

    int a = 56;
    int b = 89;
    cout << max(a, b);
    cout << min(a, b);

    swap(a, b);
    reverse(arr.begin(), arr.end());

    rotate(arr.begin(), arr.begin() + 1, arr.end());
    return 0;
}