#include <iostream>
#include <vector>
using namespace std;
// Vectors:- Dynamically array creation and easily resizable.
/*
    Some notable functions of the vectors are:-
    ->push_back()
    ->pop_back()
    ->size()
    ->resize(n) Resizes vector to contain n elements
    ->empty()  Returns whether vector is empty
    ->insert(index,value)
    ->erase(index)
    ->clear()  Clear all vector
 */
void printVector(vector<int> vector1)
{
    for (int i = 0; i < vector1.size(); i++)
    {
        cout << vector1[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> vector1;
    for (int i = 0; i <= 100; i++)
    {
        vector1.push_back(i);
    }
    printVector(vector1);
    for (int i = 0; i <= 50; i++)
    {
        vector1.pop_back();
    }
    printVector(vector1);
    // cout<<vector1.begin()<<endl;
    // cout<<vector1.end()<<endl;
    vector1.resize(100);
    cout << vector1.size() << endl;
    vector1.clear();
    if (vector1.empty())
    {
        cout << "Vector is empty." << endl;
    }
    else
    {
        cout << "Vector is not Empty." << endl;
    }

    // Sum can be found with the help of accumulate() function provided in STL.
    // accumulate(first_index, last_index, initial value of sum);

    // Max or Maximum element can be found with the help of *max_element() function provided in STL. 
    // *max_element (first_index, last_index);
    
    return 0;
}