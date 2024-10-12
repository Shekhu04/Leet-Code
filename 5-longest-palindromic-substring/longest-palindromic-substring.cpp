#include <string>
#include <algorithm> // For std::max

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.length();
        if (n <= 1) {
            return s; // A single character or empty string is already a palindrome
        }

        int start = 0, maxLength = 1; // Start position and length of the longest palindrome

        // Helper function to expand around the center
        auto expandFromCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1;  // Length of the palindrome
        };

        // Loop through each character to find the longest palindrome
        for (int i = 0; i < n; i++) {
            // Check odd-length palindromes (single character center)
            int oddLength = expandFromCenter(i, i);
            // Check even-length palindromes (two-character center)
            int evenLength = expandFromCenter(i, i + 1);

            // Find the maximum of the two palindrome lengths
            int currentMaxLength = max(oddLength, evenLength);

            // Update the start and maxLength if a longer palindrome is found
            if (currentMaxLength > maxLength) {
                maxLength = currentMaxLength;
                start = i - (maxLength - 1) / 2;
            }
        }

        // Return the longest palindrome found
        return s.substr(start, maxLength);
    }
};
