#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dominantIndex(vector<int>& nums) {
    
    int maximum = *max_element(nums.begin(), nums.end());
    int idx = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == maximum)
            idx = i;
        
        if(nums[i] != maximum && 2*nums[i] > maximum) 
            return -1;
    }

    return idx;
}

int main(){

    vector<int> nums = {3,6,1,0};

    cout << dominantIndex(nums);

    return 0;
}