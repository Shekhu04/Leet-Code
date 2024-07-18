/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    const n = nums.length; // size of array
    const ls = []; // list of answers

    const mpp = new Map(); // declaring a map

    const mini = Math.floor(n / 3); // Least occurrence of majority element (n/3 times, not +1)

    for (let i = 0; i < n; i++) {
        if (mpp.has(nums[i])) {
            mpp.set(nums[i], mpp.get(nums[i]) + 1);
        } else {
            mpp.set(nums[i], 1);
        }
    }

    for (let [key, value] of mpp) {
        if (value > mini) {
            ls.push(key);
        }
    }

    return ls;
};
