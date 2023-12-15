int sumByD(vector<int>&arr, int div){
	int n = arr.size();
	int sum = 0;
	for(int i = 0; i<n; i++){
		sum += ceil((double)(arr[i])/(double)(div));
	}
	return sum;
}

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        /*Brute force approach
	int n = nums.size();
	//Finding max element
	int maxi = *max_element(nums.begin(),nums.end());

	//Find the smallest divisor
	for(int d = 1; d <= maxi; d++){
		//Find the summation result
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += ceil((double)(nums[i])/ (double)(d));
		}
		if(sum <= threshold){
			return d;
		}
	
	}
		return -1;*/

        //Optimal Approach
	int n = nums.size();
	if(n > threshold) return -1;
	int low = 1, high = *max_element(nums.begin(),nums.end());

	//Applying Binary Search
	while(low <= high){
		int mid = (low+high)/2;
		if(sumByD(nums, mid) <= threshold){
			high = mid-1;
		}
		else low = mid+1;
	}
	return low;
    }
};