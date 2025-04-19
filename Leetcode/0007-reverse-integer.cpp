/* 7 - REVERSE INTEGER
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
*/
#include <iostream>
#include <limits>
#include <limits.h>

using namespace std;

int main() {
    int x = 153429;

    bool negative = x < 0;
    if (negative)
        x = -x;

    int reversed = 0;
    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        if (reversed > (INT_MAX / 10) ||
            (reversed == INT_MAX / 10 && digit > 7)) {
            return 0;
        }

        reversed = reversed * 10 + digit;
    }

    cout << (negative ? -reversed : reversed);    
}