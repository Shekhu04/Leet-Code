/*bool binarySearch(vector<int>&nums, int target){
    int n = nums.size();
    int low=0, high = n-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid] == target) return true;
        else if(target > nums[mid]) low=mid+1;
        else high = mid-1;
    }
    return false;
}*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int n = matrix.size(); //size of row
          int m = matrix[0].size(); //size of column

      /*BFA
      //traverse the matrix
      for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
              if(matrix[i][j] == target) return true;
          }
      } 
      return false;*/

     /*Better Approach
      for (int i = 0; i < n; i++) {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
            return binarySearch(matrix[i], target);
        }
    }
    return false;
    }*/

    //Optimal Approach
     int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
    }
};