// Extend the Array prototype with a custom last method
Array.prototype.last = function() {
    // Check if the array is not empty
    if (this.length > 0) {
        // Return the last element
        return this[this.length - 1];
    } else {
        // Return -1 if the array is empty
        return -1;
    }
};

// Example usage
const nums1 = [null, {}, 3];
console.log(nums1.last()); // Output: 3

const nums2 = [];
console.log(nums2.last()); // Output: -1