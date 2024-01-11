class Solution {
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    // Two variables to store the previous results.
    int prevFirst = 0;
    int prevSecond = 0;

    for (int i = 0; i < n; i++){
        int temp = prevFirst;
        prevFirst = max(prevSecond + nums[i], prevFirst);
        prevSecond = temp;
    }
    return prevFirst;
    }
};