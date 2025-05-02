/* 242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Algoritmo mais fácil de escrever O(nlogn)
bool isAnagram_(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

// Algoritmo mais rápido de executar O(max(m, n, 26))
bool isAnagram(string s, string t){
    vector<int> l(27, 0);
    for(auto c : s){
        l[c-'a'] += 1;
    }
    for(auto c : t){
        l[c-'a'] -= 1;
    }
    for(auto e: l) 
        if(e != 0) 
            return false;
    
    return true;
}

int main(){

    cout << isAnagram("cat", "rat");

    return 0;
}