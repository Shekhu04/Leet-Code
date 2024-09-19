class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        /*BFA
        vector<int> pos;
        vector<int> neg;

        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }

        for(int i = 0; i < nums.size()/2; i++){
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        return nums; */

        //OA
        int n = nums.size();
        vector<int> ans(n,0);

        int posIndex = 0;
        int negIndex = 1;

        for(int i = 0; i<n; i++){
            if(nums[i] < 0) {
               ans[negIndex] = nums[i];
               negIndex += 2;
            }

            else {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return ans;
    }
};