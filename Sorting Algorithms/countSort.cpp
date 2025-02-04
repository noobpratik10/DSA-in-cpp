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

int maximum(int array[], int n)
{
    int max = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
void countSort(int *array, int n)
{
    // Find max element in the array
    int max = maximum(array, n);
    // Make and initialize countArray to zero
    int *countArray = (int *)malloc((max + 1) * sizeof(int));

    for (int i = 0; i < max + 1; i++)
    {
        countArray[i] = 0;
    }

    // Increment corresponding index in countArray;
    for (int i = 0; i < n; i++)
    {
        countArray[array[i]] = countArray[array[i]] + 1;
    }

    // Final sorted array
    int i = 0; // countArray index
    int j = 0; // givenArray index
    while (i <= max)
    {
        if (countArray[i] > 0)
        {
            array[j] = i;
            j++;
            countArray[i]--;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int array[12] = {5, 2, 1, 3, 10, 11, 9, 5, 7, 6, 8, 2};
    int n = 12;
    printArray(array, n);
    countSort(array, n);
    printArray(array, n);
    return 0;
}