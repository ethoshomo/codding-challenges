#include <iostream>
#include <vector>

using namespace std;


void helper(string s, string ns, int n, vector<string>& r){
    if (n == static_cast<int>(s.length())) {
        r.push_back(ns);
        return;
    }

    if(s[n] >= 47 && s[n] <= 58)
        helper(s, ns+s[n], n+1, r);
    else if(s[n] >= 65 && s[n] <= 90){
        helper(s, ns+s[n], n+1, r);
        helper(s, ns+(char)(s[n]+32), n+1, r);
    }
    else{
        helper(s, ns+(char)(s[n]-32), n+1, r);
        helper(s, ns+s[n], n+1, r);
    }

}

// Versão recursiva
vector<string> letterCasePermutation_recursive(string s) {
    vector<string> r;
    string ns = "";
    helper(s, ns, 0, r);
    return r;
}

// Versão iterativa
vector<string> letterCasePermutation(string S) {
    vector<string> ans;
    ans.push_back(S);
    for(int i = 0; i < S.size(); i++){
        char c = S[i];
        if(isalpha(c)){
            vector<string> tmpv;
            for(string prevS : ans){
                string tmp(prevS.begin(), prevS.end());
                if(islower(c)){
                    tmp[i] = toupper(c);
                }else if(isupper(c)){
                    tmp[i] = tolower(c);
                }
                tmpv.push_back(tmp);
            }
            //concatenate
            ans.insert(ans.end(), tmpv.begin(), tmpv.end());
        }
    }
    
    return ans;
}

int main(){

    string s = "a1b2";

    vector<string> r = letterCasePermutation(s);

    for(auto a: r) cout << a << ' ';

    return 0;
}