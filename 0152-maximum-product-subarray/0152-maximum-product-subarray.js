/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    let n = nums.length;

    // Initialize variables to store the product of the prefix and suffix
    let pre = 1, suff = 1;

    // Initialize the answer with the smallest possible safe integer
    let ans = Number.MIN_SAFE_INTEGER;

    // Loop through the array to calculate the prefix and suffix products
    for(let i = 0; i < n; i++){
        // If the prefix product becomes zero, reset it to 1
        if(pre == 0) pre = 1;

        // If the suffix product becomes zero, reset it to 1
        if(suff == 0) suff = 1;

        // Multiply the prefix product with the current element
        pre *= nums[i];

        // Multiply the suffix product with the element from the end of the array
        suff *= nums[n-i-1];

        // Update the answer with the maximum of the current prefix product, suffix product, and previous maximum
        ans = Math.max(ans, pre, suff);
    }

    // Return the maximum product found
    return ans;
};
