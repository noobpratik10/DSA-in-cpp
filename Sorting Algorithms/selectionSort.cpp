#include <iostream>
using namespace std;
// Selection Sort:-
/*  Its one of the most basic sorting algorithms
    ->Its time complexity is O(n^2)
    ->Its space complexity is O(1)

    ->Here first we select smallest element from the array and
    add it to new list(or swap). This procedure is repeated for
    every element in the array */
void printArray(int array[], int n)
{
    cout << "Elements in the array are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
// 1 3 10 4 2
void selectionSort(int *array, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // swapping first element of sorted part with min number.
        int temp = array[indexOfMin];
        array[indexOfMin] = array[i];
        array[i] = temp;
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
    selectionSort(array, n);
    printArray(array, n);
    return 0;
}