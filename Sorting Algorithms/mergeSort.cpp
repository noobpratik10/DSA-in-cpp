#include <iostream>
using namespace std;

/*
    Merge sort is a recursive algorithm that continuously splits
    the array in half until it cannot be further divided i.e.,
    the array has only one element left (an array with one element is
    always sorted). Then the sorted subarrays are merged into
    one sorted array.
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

void merge(int array[], int low, int mid, int high)
{
    int tempArray[high + 1]; //---->tempArray
    int i = low;             //---->left subArray index
    int j = mid + 1;         //---->right subArray index
    int k = low;             //---->tempArray index

    // checking subArray for smaller element then adding to temp
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            tempArray[k] = array[i];
            i++;
            k++;
        }
        else
        {
            tempArray[k] = array[j];
            j++;
            k++;
        }
    }

    // Add remaining elements of left subarray
    while (i <= mid)
    {
        tempArray[k] = array[i];
        i++;
        k++;
    }

    // Add remaining elements of right subarray
    while (j <= high)
    {
        tempArray[k] = array[j];
        j++;
        k++;
    }

    // Copy all elements back to original array
    for (int i = low; i <= high; i++)
    {
        array[i] = tempArray[i];
    }
}

void mergeSort(int array[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
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
    mergeSort(array, 0, n - 1);
    printArray(array, n);

    return 0;
}