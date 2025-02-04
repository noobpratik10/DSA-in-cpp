#include <iostream>
using namespace std;

bool binarySearch(int low, int high, int array[], int x)
{
    // Base Case
    if (low > high) //--->element not found
    {
        return false;
    }

    int mid = low + (high - low) / 2;
    cout << "Value of mid is :" << array[mid] << endl;
    if (x == array[mid]) //--->element found
    {
        return true;
    }

    else
    {

        bool remainingPart;
        if (array[mid] < x)
        {
            remainingPart = binarySearch(mid + 1, high, array, x);
            return remainingPart;
        }
        else
        {
            remainingPart = binarySearch(low, mid - 1, array, x);
            return remainingPart;
        }
    }
}

int main()
{
    int n;
    cout << "ENter the size of the array here:" << endl;
    cin >> n;

    int array[n];
    cout << "Enter the elements of the array here:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int x;
    cout << "Enter the element to sarch here:" << endl;
    cin >> x;

    if (binarySearch(0, n - 1, array, x))
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}