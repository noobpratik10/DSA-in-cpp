#include <bits/stdc++.h>
using namespace std;

class ManacherAlgo
{
private:
    string s;
    string t;      // Transformed string with # inserted
    vector<int> p; // p array to store the radius of the palindrome

public:
    ManacherAlgo(string s)
    {
        this->s = s;
        // Transform the string by adding '#' between characters and at the ends
        for (auto i : s)
        {
            this->t += '#';
            this->t += i;
        }
        this->t += '#';
        // Resize p to be the length of the transformed string
        this->p.resize(t.length());
    }

    void runManacher()
    {
        int n = t.length();
        int c = 0, r = 0; // Center and right boundary of the current palindrome

        for (int i = 0; i < n; i++)
        {
            int mirror = 2 * c - i; // Mirror of i around the center c
            if (i < r)
                p[i] = min(r - i, p[mirror]);
            else
                p[i] = 0;

            // Expand the palindrome centered at i
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1])
                p[i]++;

            // Update center and right boundary if the palindrome at i expands beyond r
            if (i + p[i] > r)
            {
                c = i;
                r = i + p[i];
            }
        }
    }

    // Get the length of the longest palindrome centered at 'center'
    // 'odd' is true if we want the longest odd-length palindrome, false for even-length
    int getLongest(int center, bool odd)
    {
        int pos = 2 * center + 1; // Position in transformed string for the center
        if (!odd)
            pos++;         // Move to the even length center position
        return p[pos] / 2; // Divide by 2 to get the length in the original string
    }

    // Check if the substring from index l to r is a palindrome
    bool checkPalin(int l, int r)
    {
        int center = (l + r) / 2;
        bool odd = (r - l + 1) % 2 == 1;
        return (r - l + 1) <= getLongest(center, odd);
    }
};

int main()
{
    string s = "babbabbabc";

    ManacherAlgo ma(s);
    ma.runManacher();

    cout << "Longest Palindrome at index:-" << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << i << " " << ma.getLongest(i, false) << endl;
    }

    cout << "Check if palindrome at:-" << endl;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            cout << i << " " << j << " " << ma.checkPalin(i, j) << endl;
        }
    }

    return 0;
}
