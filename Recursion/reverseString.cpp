#include <iostream>
using namespace std;

void reverse(string &s, int i, int j)
{
    cout << "call received for:" << s << endl;
    // Base case
    if (i > j)
    {
        return;
    }

    // process
    swap(s[i], s[j]);

    // Recursive call
    reverse(s, i + 1, j - 1);
}

int main()
{
    cout << "Enter the string :" << endl;
    string s;
    cin >> s;
    reverse(s, 0, s.length() - 1);

    cout << s;
    return 0;
}