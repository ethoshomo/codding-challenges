/*
67. Add Binary

Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
 
Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/
#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

// Lógica completa - O(max(m, n)) - Bateu 100%
string addBinary(string a, string b) {

    if(b.size() > a.size()) 
        swap(a,b);

    int m = a.size()-1;
    int n = b.size()-1;
    int overflow = 0;
    string result;

    while(m >= 0 && n >= 0){
        if(a[m] == '0' && b[n] == '0'){
            if(overflow) {
                result.push_back('1');
                overflow = 0;            
            }
            else{
                result.push_back('0');
            }
        }
        else if (a[m] == '1' && b[n] == '1'){
            if(overflow){
                result.push_back('1');
                overflow = 1;
            }
            else{
                result.push_back('0');
                overflow = 1;
            }
        }
        else{
            if(overflow){
                result.push_back('0');
                overflow = 1;
            }
            else{
                result.push_back('1');
                overflow = 0;
            }
        }
        m--;
        n--;
    }

    while(m >= 0){
        if(!overflow){
            result.push_back(a[m]);
        }
        else if(overflow){
            if(a[m] == '0'){
                result.push_back('1');
                overflow = 0;
            }
            else{
                result.push_back('0');
            }
        }
        m--;
    }

    if(overflow) result.push_back('1');

    return string(result.rbegin(), result.rend());
}

// Lógica compacta
string addBinary_(string a, string b) {
    string res;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        if (i >= 0) carry += a[i--] - '0';
        if (j >= 0) carry += b[j--] - '0';
        res += carry % 2 + '0';
        carry /= 2;
    }
    reverse(begin(res), end(res));
    return res;        
}

int main(){

    string a = "11", b = "1";

    cout << addBinary(a, b);

    return 0;
}