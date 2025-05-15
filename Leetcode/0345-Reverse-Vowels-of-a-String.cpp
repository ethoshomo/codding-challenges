/*345. Reverse Vowels of a String

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:
Input: s = "IceCreAm"
Output: "AceCreIm"
Explanation:
The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:
Input: s = "leetcode"
Output: "leotcede"

Constraints:
1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/
#include <iostream>
#include <string>

using namespace std;

string reverseVowels(string s) {
    
    int l = 0, r = s.size()-1;
    while(l < r){
        while(l < s.size() && tolower(s[l]) != 'a' && tolower(s[l]) != 'e' &&
                tolower(s[l]) != 'i' && tolower(s[l]) != 'o' &&
                tolower(s[l]) != 'u') l++;

        while(r >= 0 && tolower(s[r]) != 'a' && tolower(s[r]) != 'e' &&
                tolower(s[r]) != 'i' && tolower(s[r]) != 'o' &&
                tolower(s[r]) != 'u') r--;
        
        if(l < r) swap(s[l], s[r]);
        l++;
        r--;
    }

    return s;
}

int main(){

    string s = "IceCreAm";
    cout << reverseVowels(s);
    return 0;
}