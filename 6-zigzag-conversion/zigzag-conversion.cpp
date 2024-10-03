class Solution {
public:
    string convert(string s, int numRows) {
        // Create a vector of strings where each element corresponds to a row
        vector<string> ans(numRows);

        // If there is only one row, return the string as there's no zigzag pattern.
        if (numRows == 1) return s;

        bool flag = false;  // This flag will determine the direction of the movement (up or down).
        int i = 0;          // Start at the first row (row index 0).

        // Iterate through each character of the input string.
        for (auto ch : s) {
            ans[i] += ch;  // Append the current character to the string at the current row.

            // Check if we need to reverse direction at the top (i == 0) or bottom (i == numRows - 1).
            if (i == 0 || i == numRows - 1) {
                flag = !flag;  // Toggle the flag to switch direction.
            }

            // Based on the flag, move up or down the rows.
            if (flag) {
                i++;  // Move down to the next row.
            } else {
                i--;  // Move up to the previous row.
            }
        }

        // Combine all rows to form the final zigzag string.
        string zigzag = "";
        for (auto str : ans) {
            zigzag += str;  // Concatenate each row into the final result.
        }
        return zigzag;  // Return the final zigzag string.
    }
};
