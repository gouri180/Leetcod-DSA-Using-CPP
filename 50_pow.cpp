/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn). in logn tc

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
*/

// Binary Exponentiation by squaring base and halving power
#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    long long power = n;   // Handle INT_MIN safely

    if (power < 0)
    {
        x = 1 / x;
        power = -power;
    }

    double ans = 1;

    while (power > 0)
    {
        // If power is odd
        if (power % 2 == 1)
        {
            ans *= x;
        }

        x *= x;
        power /= 2;
    }

    return ans;
}

int main()
{
    cout << myPow(2, 16) << endl;
    cout << myPow(2, 5) << endl;
    cout << myPow(2, -3) << endl;
}