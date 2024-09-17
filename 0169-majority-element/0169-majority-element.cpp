class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Using Moore's voting algo
        int cnt = 0;
        int element;
        for(int i=0; i<nums.size(); i++){
            if(cnt == 0){
                cnt = 1;
                element = nums[i];
            }
            else if(nums[i] == element) cnt++;
            else cnt--;
        }
        return element;
    }
};