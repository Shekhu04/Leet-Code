class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
    
        int sum = 0;
        int max = 0;
        
        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            if(n>max)
                max=n;
        }
        while(k>0){
            sum += max;
            k--;
            max++;
        }
        return sum;
    }
};
