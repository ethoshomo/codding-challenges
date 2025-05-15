#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

char findTheDifference(string s, string t) {
    
    char resp = 0;

    for(int i = 0; i < s.size(); i++)
        resp ^= s[i];

    for(int i = 0; i < t.size(); i++)
        resp ^= t[i];
    
    return resp;
}

int main(){

    string s = "abcd", t = "abcde";

    cout << findTheDifference(s,t);
    

    return 0;
}