class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();  // Get the size of the input array
        vector<vector<int>> ans;  // Vector to store the result quadruplets

        // Sort the array to make it easier to avoid duplicates and use two-pointer technique
        sort(nums.begin(), nums.end());

        // Loop through the array, considering each element as a potential first element of the quadruplet
        for(int i = 0; i < n; i++) {
            // Skip duplicate elements to avoid duplicate quadruplets in the result
            if(i > 0 && nums[i] == nums[i-1]) continue;

            // Loop to consider the second element of the quadruplet
            for(int j = i + 1; j < n; j++) {
                // Skip duplicate elements to avoid duplicate quadruplets in the result
                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                int k = j + 1;  // Pointer for the third element of the quadruplet
                int l = n - 1;  // Pointer for the fourth element of the quadruplet

                // Use two pointers to find pairs that, along with nums[i] and nums[j], sum up to the target
                while(k < l) {
                    // Calculate the sum of the current quadruplet
                    long long sum = nums[i];  // Start with the first element
                    sum += nums[j];  // Add the second element
                    sum += nums[k];  // Add the third element
                    sum += nums[l];  // Add the fourth element

                    if (sum == target) {
                        // If the sum is exactly equal to the target, we found a valid quadruplet
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);  // Add the quadruplet to the result vector

                        // Move both pointers inward to continue searching for other valid quadruplets
                        k++;
                        l--;

                        // Skip duplicate elements to avoid duplicate quadruplets in the result
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l+1]) l--;
                    } 
                    else if(sum < target) {
                        // If the sum is less than the target, move the left pointer to the right to increase the sum
                        k++;
                    } 
                    else {
                        // If the sum is greater than the target, move the right pointer to the left to decrease the sum
                        l--;
                    }
                }
            }
        }

        // Return the vector of all unique quadruplets that sum to the target
        return ans;
    }
};
