#include <iostream>
using namespace std;

bool findElement(int n, int array[], int x)
{

    // Base Case
    if (n == 0)
    {
        return false;
    }
    if (x == array[0])
    {
        return true;
    }
    else
    {
        // Recursive call
        bool remainingPart = findElement(n - 1, array + 1, x);
        return remainingPart;
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
    cout << "Enter the element to search" << endl;
    cin >> x;

    if (findElement(n, array, x))
    {
        cout << "Element present" << endl;
    }
    else
    {
        cout << "Element absent" << endl;
    }
    return 0;
}