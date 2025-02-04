#include <iostream>
using namespace std;

// int binarySearch(int x, int low, int high, int array[])
// {

//     //Base Condition

//     // Recursive calls
//     if (x < mid)
//     {
//         high = mid;
//         binarySearch(x, low, high, array);
//     }
//     else if (x > mid + 1)
//     {
//         low = mid;
//         binarySearch(x, low, high, array);
//     }
// }

bool isSorted(int array[], int n)
{
    // Base Condition
    if (n == 0 || n == 1)
    {
        return true;
    }

    // Processing
    if (array[0] > array[1])
    {
        return false;
    }

    else
    {
        // Recursive call
        bool remainingPart = isSorted(array + 1, n - 1); //--->ye pointer hote hai
        return remainingPart;
    }
}
int main()
{
    int n;
    cout << "Enter the size of the aarray:" << endl;
    cin >> n;

    cout << "Enter the elements of  the array:" << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[n];
    }

    if (isSorted(arr, n))
    {
        cout << "Is sorted" << endl;
    }
    else
    {
        cout << "Is not sorted" << endl;
    }
    return 0;
}