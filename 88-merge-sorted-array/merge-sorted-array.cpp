class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0; // Initialize two pointers: i for nums1 and j for nums2
        vector<int> a = nums1; // Create a copy of nums1, as we'll overwrite nums1 during the merge
        int k = 0; // Pointer for placing elements in the correct position in nums1

        // While both nums1 and nums2 still have elements to compare
        while(i < m && j < n) {
            if(a[i] < nums2[j]) { 
                // If the current element in nums1's copy is smaller, place it in nums1
                nums1[k] = a[i]; 
                i++; // Move to the next element in the copied nums1
            } else {
                // If the current element in nums2 is smaller or equal, place it in nums1
                nums1[k] = nums2[j];
                j++; // Move to the next element in nums2
            }
            k++; // Move the pointer for nums1 to place the next element
        }

        // If there are any remaining elements in the copied nums1, place them in nums1
        while(i < m) {
            nums1[k++] = a[i++]; // Add remaining elements from nums1's copy to nums1
        }

        // If there are any remaining elements in nums2, place them in nums1
        while(j < n) {
            nums1[k++] = nums2[j++]; // Add remaining elements from nums2 to nums1
        }
    }
};
