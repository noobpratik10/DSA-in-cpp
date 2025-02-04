#include <bits/stdc++.h>
using namespace std;

/*
Bit Operators in C++:-
1) The & (bitwise AND) in C takes two numbers as operands and does
    AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.

2) The | (bitwise OR) in C takes two numbers as operands and does
    OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1.

3) The ^ (bitwise XOR) in C takes two numbers as operands and does
    XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different.

4) The << (left shift) in C takes two numbers, the left shifts the bits of the
    first operand, and the second operand decides the number of places to shift.

5) The >> (right shift) in C takes two numbers, right shifts the bits
    of the first operand, and the second operand decides the number of places to shift.

6) The ~ (bitwise NOT) in C takes one number and inverts all bits of it.
*/

// Some basic functions of bit manipulation in cpp:-
// Function to swap 2 numberse:-
void swap(int &a, int &b)
{
    a = a ^ b; // we know that a^a=0
    b = a ^ b; // b=(a^b)^b =a
    a = a ^ b; // a=(a^b)^a =b
}

// check if ith bit is set or not
bool checkBit(int n, int i)
{
    if (n >> i & 1) // another way:-(n&(1<<i))
        return true;
    else
        return false;
}

// Function to set the ith bit:-
int setBit(int n, int i)
{
    return n | 1 << i;
}

// Function to clear the ith bit:-
int clearBit(int n, int i)
{
    return n & ~(1 << i);
}

// Function to toggle the ith bit:-
int toggleBit(int n, int i)
{
    return n ^ 1 << i;
}

// Function to remove the last set bit:-
int removeLastSetBit(int n, int i)
{
    return n & (n - 1);
}

// Function to check if its power of 2:-
bool checkPowerTwo(int n)
{
    return !(n & (n - 1));
}

// Count no. of set bits
int countSetBits(int n)
{
    int cnt = 0;
    while (n != 0)
    {
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}