class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> ans; // Array to store the result triplets
        int n = nums.size();

        // Sort the array to easily skip duplicates and use two pointers technique
        std::sort(nums.begin(), nums.end());

        // Loop through the array, considering each element as a potential first element of the triplet
        for(int i = 0; i < n; i++) {
            // Skip duplicate elements to avoid duplicate triplets in the result
            if(i != 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1; // Pointer for the second element of the triplet
            int k = n - 1; // Pointer for the third element of the triplet

            // Use two pointers to find pairs that, along with nums[i], sum up to zero
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    // If the sum is less than zero, move the left pointer (j) to the right to increase the sum
                    j++;
                } else if(sum > 0) {
                    // If the sum is greater than zero, move the right pointer (k) to the left to decrease the sum
                    k--;
                } else {
                    // If the sum is exactly zero, we found a valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]}); // Add the triplet to the result array

                    // Move both pointers inward to continue searching for other valid triplets
                    j++;
                    k--;

                    // Skip duplicate elements to avoid duplicate triplets in the result
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        // Return the array of all unique triplets
        return ans;
    }
};