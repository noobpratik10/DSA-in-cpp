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

void insertionSort(int *array, int n, int sorted = 0)
{
    // Base case //--> array is sorted
    if (sorted == n)
    {
        return;
    }

    // Processing //---->ek case solve karo
    int key = array[sorted + 1];
    int j = sorted;
    while (j >= 0 && array[j] > key)
    {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = key;

    // Recursive call    //-->baki recursive karega
    insertionSort(array, n, sorted + 1);
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
    insertionSort(array, n);
    printArray(array, n);

    return 0;
}