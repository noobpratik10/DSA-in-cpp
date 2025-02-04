#include <iostream>
using namespace std;

void printArray(int array[], int n)
{
    cout << "Elements in the array are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selectionSort(int *array, int n, int sorted = 0)
{
    // Base case-->array already sorted
    if (sorted == n) // starting and size are same
    {
        return;
    }

    // Processing -->ek ke liye solve karo
    int indexOfMin = sorted;
    for (int j = sorted + 1; j < n; j++)
    {
        if (array[j] < array[indexOfMin])
        {
            indexOfMin = j;
        }
    }
    swap(array[sorted], array[indexOfMin]);

    // Recursive call
    selectionSort(array, n, sorted + 1);
}
int main()
{

    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    printArray(array, n);
    selectionSort(array, n);
    printArray(array, n);

    return 0;
}