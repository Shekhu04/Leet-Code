class Solution {
public:
    void sortColors(vector<int>& nums) {
        int d=nums.size();
        for(int i=0;i<d-1;i++)
    {
        for(int j=0;j<d-i-1;j++)
        {
        if(nums[j]>nums[j+1])
        {
            int t;
            t=nums[j];
            nums[j]=nums[j+1];
            nums[j+1]=t;
        }
        }
    }
    }
};
