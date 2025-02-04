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
    // Base case--> array already sorted
    if (n == 0 || n == 1)
    {
        return;
    }
    else
    {
        // Process--> ek case solve karo
        for (int i = 0; i < n - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
            }
        }

        // Recursive call --->baki apne aap solve ho jayega
        bubbleSort(array, n - 1);
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
    bubbleSort(array, n);
    printArray(array, n);

    return 0;
}