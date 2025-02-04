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

void bubbleSort(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "th pass is going on" << endl;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *array, int n)
{
    int isSorted = 0;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "th pass is going on" << endl;
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                isSorted = 0;
            }
        }
        if (isSorted == 1)
        {
            return;
        }
    }
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
    // bubbleSort(array, n);
    // printArray(array, n);
    bubbleSortAdaptive(array, n);
    printArray(array, n);
    return 0;
}