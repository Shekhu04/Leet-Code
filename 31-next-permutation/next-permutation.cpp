#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();

        // Longer Prefix match
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) { // breakout point
                ind = i;
                break;
            }
        } 
        
        //if there is no breaking point 
        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        //fin next greater element and swap
        for(int i = n - 1; i > ind; i--) {
            if(nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        
        //reverse the right half
        reverse(nums.begin() + ind + 1, nums.end());
    }
};


