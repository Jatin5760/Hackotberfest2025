// C++ program to count decoding ways of a digit string
// using recursion.
#include <bits/stdc++.h>
using namespace std;

// Helper function to recursively calculate decoding ways.
int decodeHelper(string &digits, int index)
{

    int n = digits.length();

    // Base case: If we reach the end of the string,
    // return 1 as it signifies a valid decoding.
    if (index >= n)
    {
        return 1;
    }

    int ways = 0;

    // Single-digit decoding: check if current digit is not '0'.
    if (digits[index] != '0')
    {
        ways = decodeHelper(digits, index + 1);
    }

    // Two-digit decoding: check if next two digits are valid.
    if ((index + 1 < n) && ((digits[index] == '1' && digits[index + 1] <= '9') ||
                            (digits[index] == '2' && digits[index + 1] <= '6')))
    {

        ways += decodeHelper(digits, index + 2);
    }

    return ways;
}

// Function to count decoding ways for the
// entire string.
int countWays(string &digits)
{

    return decodeHelper(digits, 0);
}

int main()
{

    string digits = "121";

    cout << countWays(digits) << endl;

    return 0;
}
