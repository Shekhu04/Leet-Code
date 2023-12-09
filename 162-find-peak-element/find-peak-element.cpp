class Solution {
public:
    int findPeakElement(vector<int>& nums) {
   
      
        int n = nums.size();

        /*brute force approach

        for(int i = 0; i<=n; i++) 
        {
            if((i==0 || nums[i] > nums[i-1]) 
                          && (i == n-1 || nums[i] > nums[i+1]))
                          return i;
                          
        }
        */

        //optimal approach using binary search

      //edge cases
       if (n==1) return 0; //single element in array
       if(nums[0] > nums[1]) return 0; //first element is the peak element
       if(nums[n-1] > nums[n-2]) return n-1; //last element is the peak
 
       //updating low and high as we have solved the edge cases
       int low=1,high=n-2;
       while(low <= high)
     { 
        int mid = low + (high-low)/2;

        //if arr[mid] is the peak
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

        //if we are on the left
        if(nums[mid] < nums[mid+1]) 
            //eliminate left half 
            low = mid+1;

        //if we are on the right 
        //Or mid is the common point
        else 
           //eliminate right half
           high = mid -1;
     }
     return -1;   
    }
};