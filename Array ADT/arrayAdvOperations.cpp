#include<iostream>
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

}

int main(){
    int capacity = 100;
    int array[100] = {7, 4, 5, 6, 8, 3, 3, 54, 6, 8, 45, 25, 58, 96, 21, 4, 233, 25, 7};
    int size = 19;
    int element, index;
    arrayDisplay(array, capacity, size);
    cout << "Write the element to be used to perform operation on the array here:" << endl;
    cin >> element;
    cout << "Write the index to be used to perform operation on the array here:" << endl;
    cin >> index;
return 0;
}