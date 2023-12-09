class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = INT_MAX;

        while(low <= high) {
            int mid = low + (high-low)/2;

            /*if search space is already sorted then 
		    arr[low] will always be minimum in that search space*/

		     if(nums[low] <=  nums[high])
            {
			ans = min(ans,nums[low]);
			break;
		    }

		     //if left part is sorted
		    if(nums[low] <= nums[mid]) 
            {
			
			//keep the minimum
			ans = min(ans,nums[low]);

			//eliminate left half
			low = mid+1;
		    }

		    //if right part is sorted
		    else 
            {
			ans = min(ans ,nums[mid]);

			//eliminate right half
			high = mid-1;
		    }
	    }
	return ans;
    }
};