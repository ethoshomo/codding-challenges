#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int main(){

    vector<int> nums = {2,2,1,1,1,2,2};

    sort(nums.begin(), nums.end());

    int c = 0, aV = nums[0], m = nums[0], cM = 1;
    for(size_t i = 0; i < nums.size(); i++){
        if (nums[i] != aV) {
            c = 1;
            aV = nums[i];
        }
        else{
            c += 1;
        }
        
        if(c > cM){
            m = aV;
            cM = c;
        }

    }
    
    cout << m;

    return 0;
}