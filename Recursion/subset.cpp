#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//      Make and return all the possible subsets(power set) of the given array

void printArray(vector<int> array)
{
    cout << "Elements in the array are:" << endl;
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void powerSet(vector<int> array, vector<int> output, int index, vector<vector<int>> &ans)
{
    // Base call
    if (index >= array.size())
    {
        ans.push_back(output);
        return;
    }

    // Recursive call
    // exclude
    powerSet(array, output, index + 1, ans);
    // include
    int element = array[index];
    output.push_back(element);
    powerSet(array, output, index + 1, ans);
}

int main()
{

    vector<int> array;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        array.push_back(j);
    }

    printArray(array);

    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    powerSet(array, output, index, ans);

    cout << "Power set of the array is: " << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}