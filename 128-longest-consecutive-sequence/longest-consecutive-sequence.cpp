class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         int n = nums.size();
    if (n == 0) return 0;

    // Sort the array
    sort(nums.begin(), nums.end());

    int longest = 1;
    int currentLength = 1;

    for (int i = 1; i < n; ++i) {
        // If current element is consecutive to the previous element
        if (nums[i] == nums[i - 1] + 1) {
            currentLength++;
        } 
        // If the current element is the same as the previous element, skip it
        else if (nums[i] != nums[i - 1]) {
            // Reset current length
            currentLength = 1;
        }
        // Update the longest length found so far
        longest = max(longest, currentLength);
    }
    return longest;
    }
};