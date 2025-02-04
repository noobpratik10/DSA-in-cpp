#include <iostream>
using namespace std;
// Practice set of questions for array:-
// in array find:-
//  1)swap alternate
//  2)unique
//  3)find duplicate
//  4)find  Mode
//  5)array intersection(common elements in both arrays)
//  6)pair sum
//  7)triplet sum
//  8)sort zero's and one's

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void swapAlternate(int *array, int n)
{
    // eg input 1 4 5 10 3 2 6
    for (int i = 0; i < n - 2; i += 2)
    {
        int temp = array[i + 1];
        array[i + 1] = array[i];
        array[i] = temp;
    }
    // eg output 4 1 10 5 2 3 1
}

void uniqueCount(int array[], int n)
{
    // eg input 1 2 5 2 1 10 9 5
    int uniqElement = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] == array[j])
            {
                uniqElement--;
            }
        }
    }
    cout << "No. of unique elements in the array are:" << uniqElement << endl;
    // eg output 5
}

void duplicateCounter(int array[], int n)
{
    // eg input 1 2 5 2 1 10 9 5
    int dupliCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] == array[j])
            {
                dupliCount++;
            }
        }
    }

    cout << "No. of duplicate Number are :" << dupliCount << endl;
    // eg output 3
}

void freqCounter(int array[], int n)
{
    // eg input 1 2 5 2 1 10 9 5 2 2
    int maxfreqElement, maxFreq = 1;
    for (int i = 0; i < n; i++)
    {
        // maxfreqElement=array[i];
        int freqOfI = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] == array[j])
            {
                freqOfI++;
            }
        }
        if (freqOfI > maxFreq)
        {
            maxFreq = freqOfI;
            maxfreqElement = array[i];
        }
    }

    cout << "Element occuring most is :" << maxfreqElement << endl;
    cout << "Its frequency is :" << maxFreq << endl;
    // eg output element: 2 freq: 4
}

void arrayIntersection(int array1[], int array2[], int n1, int n2)
{
    // eg input array1 :1 4 5 7 10 9 6 1
    //          array2 :1 7 5 3 8  2 4
    cout << "Common Elements in the array are:" << endl;
    int comIndex = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (array1[i] == array2[j])
            {
                cout << array1[i] << " ";
                comIndex++;
            }
        }
    }
    cout << endl;
    cout << "No of common elements are: " << comIndex << endl;
    // eg common elements 1 4 5 7 1 noofele:5
}

void pairSum(int array[], int n)
{
    //  eg input 1 4 5 10 3 2 6
    cout << "Sum of pairs for this array are: " << endl;
    for (int i = 0; i < n - 1; i++)
    {
        cout << array[i] + array[i + 1] << " ";
    }
    cout << endl;
    // eg output 5 9 15 13 5 8
}

void tripletSum(int array[], int n)
{
    //  eg input 1 4 5 10 3 2 6
    cout << "Sum of triplets for this array are: " << endl;
    for (int i = 0; i < n - 2; i++)
    {
        cout << array[i] + array[i + 1] + array[i + 2] << " ";
    }
    cout << endl;
    //  eg output 10 19 18 15 11
}

void sortZeroOne(int *array, int n)
{
    // eg input 0 1 1 0 0 1 1 1 0 1 0 1 0 1 0 0 1
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    cout << "Sorted array of 0s and 1s: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    // eg output 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1
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

    // swapAlternate(array, n);
    // uniqueCount(array, n);
    // duplicateCounter(array, n);
    // freqCounter(array, n);

    // int array1[8] = {1, 4, 5, 7, 10, 9, 6, 1};
    // int array2[7] = {1, 7, 5, 3, 8, 2, 4};
    // arrayIntersection(array1, array2, 8, 7);

    // pairSum(array, n);
    // tripletSum(array, n);
    // sortZeroOne(array, n);

    return 0;
}