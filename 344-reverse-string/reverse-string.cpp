class Solution {
public:
    void reverseString(vector<char>& s) {
        // Get the size of the input vector
        int n = s.size();
       
        // Loop runs from the start to the middle of the vector
        // We only need to swap the first half with the second half
        for (int i = 0; i < n / 2; i++) {
            // Store the current element in a temporary variable
            int temp = s[i];
            
            // Swap the element from the front with the corresponding element from the back
            s[i] = s[n - i - 1];

            // Assign the temporary value to the corresponding position from the back
            s[n - i - 1] = temp;
        }
    }
};
