#include <iostream>
using namespace std;

int getSum(int array[], int n)
{
    // Base Condition
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return array[0];
    }
    // Recursive call
    else
    {
        int remainingSum = getSum(array + 1, n - 1);
        int sum = array[0] + remainingSum;
        return sum;
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

    cout << "Sum of all the elements in the array is :" << getSum(array, n);
    return 0;
}
