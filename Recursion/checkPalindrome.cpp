#include <iostream>
using namespace std;

bool isPalindrome(string s, int i)
{
    // Base case
    if (i > s.length() - 1 - i)
    {
        return true;
    }

    // Process
    if (s[i] != s[s.length() - 1 - i])
    {
        return false;
    }
    else
    {
        // Recursive call
        return isPalindrome(s, i + 1);
    }
}

int main()
{
    cout << "Enter the string to check palindrome :" << endl;
    string s;
    cin >> s;

    if (isPalindrome(s, 0))
    {
        cout << "It is palindrome" << endl;
    }
    else
    {
        cout << "It is not a palindrome" << endl;
    }
    return 0;
}