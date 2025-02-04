#include <iostream>
using namespace std;

/*
    What is Inversion Count??
    -->Inversion Count for an array indicates – how far (or close) the array
    is from being sorted. If the array is already sorted, then the inversion
    count is 0, but if the array is sorted in reverse order, the
    inversion count is the maximum.
*/

/*
    Naive Approach:-
    Traverse through the array, and for every index, find the number of smaller
    elements on its right side of the array. This can be done using a nested
    loop. Sum up the counts for all indices in the array and print the sum.
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

int merge(int *array, int low, int mid, int high)
{

    int tempArray[high + 1]; //---->tempArray
    int i = low;             //---->left subArray index
    int j = mid + 1;         //---->right subArray index
    int k = low;             //---->tempArray index

    int invCount = 0;
    // checking subArray for smaller element then adding to temp
    while (i <= mid && j <= high)
    {
        if (array[i] <= array[j])
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

            // because left and right subarrays are sorted, so all the
            // remaining elements in left-subarray will be greater
            // than a[j]

            invCount += mid - i;
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
    for (int i = low; i < high + 1; i++)
    {
        array[i] = tempArray[j];
    }
    return invCount;
}

int mergeSort(int *array, int low, int high)
{

    int invCount = 0;
    int mid;

    if (low < high)
    {
        // Processing
        mid = (low + high) / 2;

        // Recursive calls
        invCount += mergeSort(array, low, mid);
        invCount += mergeSort(array, mid + 1, high);
        invCount += merge(array, low, mid, high);
    }

    return invCount;
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
    cout << mergeSort(array, 0, n - 1);
    // 83, 20, 9, 50, 115, 61, 17

    return 0;
}