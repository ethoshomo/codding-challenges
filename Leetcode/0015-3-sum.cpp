/*

Casos menores que 3 impossíveis.

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum_time_exceed(vector<int>& nums) {
    int n = nums.size();

    if(n < 3) return vector<vector<int>>{};

    set<vector<int>> results;

    // Iterar por todas as máscaras possíveis de n bits
    int maxMask = 1 << n; // 2^n
    for (int mask = 0; mask < maxMask; ++mask) {

        // Verifica se a máscara tem exatamente 3 bits 1
        if (__builtin_popcount(mask) == 3) {
            vector<int> triplet;
            int sum = 0;

            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    triplet.push_back(nums[i]);
                    sum += nums[i];
                }
            }

            if (sum == 0) {
                sort(triplet.begin(), triplet.end());  // Evita duplicatas no set
                results.insert(triplet);
            }
        }
    }

    return vector<vector<int>>(results.begin(), results.end());
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum > 0) {
                --right;
            } else if (sum < 0) {
                ++left;
            } else {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;
                ++left;
                --right;
            }
        }
    }

    return result;
}


int main(){


    vector<int> v = {34,55,79,28,46,33,2,48,31,-3,84,71,52,-3,93,15,21,-43,57,-6,86,56,94,74,83,-14,28,-66,46,-49,62,-11,43,65,77,12,47,61,26,1,13,29,55,-82,76,26,15,-29,36,-29,10,-70,69,17,49};

    vector<vector<int>> r = threeSum(v);

    for(auto c : r){
        cout << "[ ";
        for(auto d : c){
            cout << d << ',';
        }
        cout << " ] ";
    }

    return 0;
}