#include <iostream>
using namespace std;

/*
    Insertion sort is a simple sorting algorithm that works similar
    to the way you sort playing cards in your hands. The array is virtually
    split into a sorted and an unsorted part. Values from the unsorted
    part are picked and placed at the correct position in the sorted part.


    To sort an array of size N in ascending order iterate over the array
    and compare the current element (key) to its predecessor, if the key
    element is smaller than its predecessor, compare it to the elements
    before. Move the greater elements one position up to make space for
    the swapped element.


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

void insertionSort(int *array, int n)
{
    int key;
    int j;
    // Loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        key = array[i];
        j = i - 1;
        // Loop for each pass
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
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
    insertionSort(array, n);
    printArray(array, n);
    return 0;
}