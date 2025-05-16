/* 415. Add Strings

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"

Constraints:
1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
    A soma de 3 numeros é mais rápida que
    criar uma variável para a soma. Isso
    se deve às operações de load e store
    no processador, que são mais lentas que
    as operações sequenciadas de soma.
*/
string addStrings(string num1, string num2){
    int idx1 = num1.size() - 1, idx2 = num2.size() - 1, carry = 0;
    string ans;

    while (idx1 >= 0 || idx2 >= 0){
        int currNum1 = idx1 >= 0 ? (num1[idx1] - '0') : 0;
        int currNum2 = idx2 >= 0 ? (num2[idx2] - '0') : 0;

        int sum = (currNum1 + currNum2 + carry) % 10;
        carry = (currNum1 + currNum2 + carry) / 10;
        ans += (sum + '0');
        idx1--;
        idx2--;
    }

    if (carry){
        ans += (carry + '0');
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

    string num1 = "0", num2 = "0";

    cout << addStrings(num1, num2);

    return 0;
}