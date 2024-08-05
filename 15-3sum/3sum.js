/**
 * @param {number[]} nums - An array of integers
 * @return {number[][]} - A 2D array containing all unique triplets [nums[i], nums[j], nums[k]]
 *                        such that they add up to zero (i.e., nums[i] + nums[j] + nums[k] == 0).
 */
var threeSum = function(nums) {
    let ans = []; // Array to store the result triplets
    let n = nums.length;

    // Sort the array to make it easier to avoid duplicates and use two pointers technique
    nums.sort((a, b) => a - b);

    // Loop through the array, considering each element as a potential first element of the triplet
    for(let i = 0; i < n; i++){
        // Skip duplicate elements to avoid duplicate triplets in the result
        if(i != 0 && nums[i] === nums[i-1]) continue;

        let j = i + 1; // Pointer for the second element of the triplet
        let k = n - 1; // Pointer for the third element of the triplet

        // Use two pointers to find pairs that, along with nums[i], sum up to zero
        while(j < k){
            let sum = nums[i] + nums[j] + nums[k];

            if (sum < 0) {
                // If the sum is less than zero, move the left pointer to the right to increase the sum
                j++;
            } else if (sum > 0) {
                // If the sum is greater than zero, move the right pointer to the left to decrease the sum
                k--;
            } else {
                // If the sum is exactly zero, we found a valid triplet
                let temp = [nums[i], nums[j], nums[k]];
                ans.push(temp); // Add the triplet to the result array

                // Move both pointers inward to continue searching for other valid triplets
                j++;
                k--;

                // Skip duplicate elements to avoid duplicate triplets in the result
                while(j < k && nums[j] === nums[j-1]) j++;
                while(j < k && nums[k] === nums[k+1]) k--;
            }
        }
    }

    // Return the array of all unique triplets
    return ans;
};
