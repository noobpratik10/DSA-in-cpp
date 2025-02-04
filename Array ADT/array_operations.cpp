#include <iostream>
using namespace std;

void arrayDisplay(int array[], int capacity, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void indexDisplay(int array[], int capacity, int size, int index)
{
    cout << array[index] << " " << endl;
    ;
}

int indexInsertion(int array[], int capacity, int size, int index, int element)
{
    if (index > size - 1)
    {
        cout << "Index out of range." << endl;
        return -1;
    }

    for (int i = size - 1; i >= index; i--)
    {
        array[i + 1] = array[i];
    }
    array[index] = element;
    size += 1;
    return 0;
}

int sortedInsertion(int array[], int capacity, int size, int element)
{

    int index;
    int i = 0;
    while (element < array[i])
    {

        i++;
    }

    for (int j = size - 1; j >= i; j--)
    {
        array[j + 1] = array[j];
    }

    array[i] = element;
    size += 1;
    return 0;
}

int indexDeletion(int array[], int capacity, int size, int index)
{
    if (index > size - 1)
    {
        cout << "Index out of range." << endl;
        return -1;
    }

    for (int i = index; i < size; i++)
    {
        array[i] = array[i + 1];
    }
    cout << "Element at" << index << "th position deleted." << endl;
    size -= 1;
    return 0;
}

int linearSearch(int array[], int size, int capacity, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            cout << "Element first found at " << i << "th position." << endl;
            return 0;
        }
    }

    cout << "Element not found." << endl;
    return -1;
}

int binarySearch(int array[], int size, int capacity, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (element > array[mid])
        {
            low = mid + 1;
        }
        else if (element == array[mid])
        {
            high = mid - 1;
        }
        else
        {
            cout << "Element found at " << mid << "th position." << endl;
            return 0;
        }
    }

    cout << "Element not found." << endl;
    return -1;
}

int elementCounter(int array[], int element, int capacity, int size)
{
    // // by linear search approach
    // int lcount = 0;
    // for (int i = 0; i < size; i++)
    // {
    //     if (element == array[i])
    //     {
    //         lcount++;
    //     }
    // }
    // cout << "Linear approach:-" << endl;
    // cout << "Element occurs in the array" << lcount << "times." << endl;

    // by binary search approach
    int bcount = 0;
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (high + low) / 2;
        if (element > array[mid])
        {
            low = mid + 1;
        }
        else if (element == array[mid])
        {
            bcount++;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Binary approach:-" << endl;
    cout << "Element occurs in the array" << bcount << "times." << endl;
    return 0;
}

int reverseArray(int array[], int capacity, int size)
{
    int i = 0, j = size - 1;
    while (i <= j)
    {
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
        i++;
        j--;
    }

    return 0;
}

int main()
{
    int capacity = 100;
    int array[100] = {7, 4, 5, 6, 8, 3, 3, 54, 6, 8, 45, 25, 58, 96, 21, 4, 233, 25, 7};
    int size = 19;
    int element, index;
    arrayDisplay(array, capacity, size);
    cout << "Write the element to be used to perform operation on the array here:" << endl;
    cin >> element;
    cout << "Write the index to be used to perform operation on the array here:" << endl;
    cin >> index;

    indexDeletion(array, capacity, size, index);
    arrayDisplay(array, capacity, size);

    indexDisplay(array, capacity, size, index);
    indexInsertion(array, capacity, size, index, element);
    arrayDisplay(array, capacity, size);

    linearSearch(array, size, capacity, element);
    binarySearch(array, size, capacity, element);

    sortedInsertion(array, capacity, size, element);
    arrayDisplay(array, capacity, size);

    elementCounter(array, element, capacity, size);
    arrayDisplay(array, capacity, size);

    reverseArray(array, capacity, size);
    arrayDisplay(array, capacity, size);

    return 0;
}