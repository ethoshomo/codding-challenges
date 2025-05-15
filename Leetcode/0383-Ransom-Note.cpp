/* 383. Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true
 
Constraints:
1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    
    vector<int> count(27, 0);

    for(int i = 0; i < magazine.size(); i++)
        count[magazine[i]-'a']++;

    for(int i = 0; i < ransomNote.size(); i++){
        if(count[ransomNote[i]-'a'])
            count[ransomNote[i]-'a']--;
        else
            return false;
    }

    return true;
}

int main(){

    string ransomNote = "aa", magazine = "ab";

    cout << canConstruct(ransomNote, magazine);

    return 0;
}