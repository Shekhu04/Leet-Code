class Solution {
public:
    std::string longestPalindrome(std::string s) {
        // If the string is empty or has only one character, it is already a palindrome
        if (s.length() <= 1) {
            return s;
        }

        // Helper function to expand from the center and find the longest palindrome
        auto expand_from_center = [&](int left, int right) {
            // Expand outwards as long as the characters match and within bounds
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Return the palindrome substring found
            return s.substr(left + 1, right - left - 1);
        };

        std::string max_str = s.substr(0, 1); // Initial longest palindrome (single character)

        // Loop through each character in the string
        for (int i = 0; i < s.length() - 1; i++) {
            // Check for odd-length palindromes (single character center)
            std::string odd = expand_from_center(i, i);
            // Check for even-length palindromes (two character center)
            std::string even = expand_from_center(i, i + 1);

            // Update max_str if a longer palindrome is found
            if (odd.length() > max_str.length()) {
                max_str = odd;
            }
            if (even.length() > max_str.length()) {
                max_str = even;
            }
        }

        return max_str; // Return the longest palindrome found
    }
};
