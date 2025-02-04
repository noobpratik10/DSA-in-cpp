#include <iostream>
using namespace std;

/*
    QuickSort is a sorting algorithm based on the Divide and Conquer algorithm that
    picks an element as a pivot and partitions the given array around the picked
    pivot by placing the pivot in its correct position in the sorted array.
*/

void printArray(int array[], int n)
{
    cout << "Elements in the array are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int partition(int *array, int low, int high)
{
    int pivot = low;
    int i = low + 1;
    int j = high;
    do
    {
        while (array[i] <= array[pivot])
        {
            i++;
        }
        while (array[j] > array[pivot])
        {
            j--;
        }
        if (i < j)
        {
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }

    } while (i < j);

    // swap pivot and a[j]--->set pivot's right position
    int temp = array[j];
    array[j] = array[pivot];
    array[pivot] = temp;

    return j;
}

void quickSort(int *array, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {

        partitionIndex = partition(array, low, high); // Index of pivot after partition
        quickSort(array, low, partitionIndex - 1);    // Sort left subArray
        quickSort(array, partitionIndex + 1, high);   // Sort right subArray
    }
}
int main()
{
    int array[12] = {5, 2, 1, 3, 10, 11, 9, 5, 7, 6, 8, 2};
    int n = 12;
    printArray(array, n);
    quickSort(array, 0, n - 1);
    printArray(array, n);
    return 0;
}