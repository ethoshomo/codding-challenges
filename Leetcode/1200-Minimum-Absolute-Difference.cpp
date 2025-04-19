#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

    vector<vector<int>> r;
    
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int minimum = INT_MAX;
    
    for(int i = 1; i < n; i++)
        minimum = min(minimum, arr[i]-arr[i-1]);
    
    for(int i = 1; i < n; i++){
        if(arr[i]-arr[i-1] == minimum) 
            r.push_back(
                vector<int>{
                    min(arr[i],arr[i-1]), 
                    max(arr[i],arr[i-1])
                }
            );
    }

    return r;
}

int main(){

    //vector<int> v = {4,2,1,3};
    vector<int> v = {1,3,6,10,15};

    vector<vector<int>> r = minimumAbsDifference(v);

    for(auto c: r){
        cout << '[';
        for(auto s: c) cout << s << ',';
        cout << "]\n";
    }

    return 0;
}