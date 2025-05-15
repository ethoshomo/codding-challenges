/* 344. Reverse String

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

Constraints:
1 <= s.length <= 105
s[i] is a printable ascii character.
*/
#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    
    int l = 0, r = s.size()-1;
    while(l < r){
        swap(s[l], s[r]);
        l++;
        r--;
    }
}

int main(){

    vector<char> s = {'H','e','l','l','o'};

    reverseString(s);

    for(auto &c : s) cout << c << ' ';

    return 0;
}