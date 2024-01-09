class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int n = matrix.size(); //size of row
      int m = matrix[0].size(); //size of column

      //traverse the matrix
      for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
              if(matrix[i][j] == target) return true;
          }
      } 
      return false;
    }
};