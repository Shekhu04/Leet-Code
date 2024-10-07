class Solution {
public:
    string largestOddNumber(string num) {
        int n = 0;

        // Calculate the length of the string manually
        while (num[n] != '\0') {
            n++;
        }

        // Traverse the string from the end to find the first odd number
        for (int i = n - 1; i >= 0; i--) {
            int digit = num[i] - '0'; // Convert character to integer
            if (digit % 2 != 0) {
                // Manually construct the substring by creating a new string up to the odd number
                string result = "";
                for (int j = 0; j <= i; j++) {
                    result += num[j];
                }
                return result;
            }
        }

        return "";
    }
};