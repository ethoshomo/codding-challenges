#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    vector<int> r(n+1, 0);
    vector<int> s;

    for(auto c: nums) 
        r[c] = 1;

    for(int i = 1; i <= n; i++)
        if(r[i] == 0) s.push_back(i);

    return s;
}

int main(){

    //vector<int> v = {4,3,2,7,8,2,3,1};
    vector<int> v = {1,1};

    vector<int> r = findDisappearedNumbers(v);

    for(auto c: r) cout << c << ' ';

    return 0;
}