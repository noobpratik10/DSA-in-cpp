/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;										// Reading input from STDIN
    cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cin >> num;
    vector<int> power;
    for (int i = 0; i < num; i++)
    {
        cin >> power[i];
    }

    int rounds;
    cin >> rounds;
    vector<int> powerB;
    for (int i = 0; i < rounds; i++)
    {
        cin >> powerB[i];
    }

    // vector<vector<int>>ans;

    for (int i = 0; i < rounds; i++)
    {
        int sum = 0;
        int count = 0;
        for (int j = 0; j < power.size(); j++)
        {
            if (power[j] <= powerB[i])
            {
                sum += power[j];
                count++;
            }
        }
        // ans[i][0]=count;
        // ans[i][1]=sum;
        cout << count << " " << sum << endl;
    }

    return 0;
}