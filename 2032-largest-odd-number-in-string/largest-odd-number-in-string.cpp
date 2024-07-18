class Solution {
public:
    // Function to find the largest odd number in a given string of digits
    string largestOddNumber(string num) {
        int n = num.length(); // Get the length of the input string

        // Traverse the string from the end to the beginning
        for (int i = n - 1; i >= 0; i--) {
            // Check if the current digit (num[i]) is odd
            if ((num[i] - '0') % 2 != 0) {
                // If it's odd, return the substring from the start to this digit (inclusive)
                return num.substr(0, i + 1);
            }
        }

        // If no odd digit is found, return an empty string
        return "";
    }
};
