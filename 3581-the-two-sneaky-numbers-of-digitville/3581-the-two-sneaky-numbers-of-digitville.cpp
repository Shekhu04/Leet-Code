class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> frequency(n,0);
        vector<int> result;
        
        for(int i = 0; i < n; i++){
            int num = nums[i];
            frequency[num]++;
        }

        for(int i = 0; i < n; i++){
            if(frequency[i] > 1){
                result.push_back(i);
            }
            if(result.size() == 2){
                break;
            }
        }
        return result;
    }
   
};