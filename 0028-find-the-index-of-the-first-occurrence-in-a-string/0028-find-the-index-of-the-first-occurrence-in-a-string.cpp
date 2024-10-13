class Solution {
public:
    int strStr(string haystack, string needle) {
        // If the length of the haystack is less than the needle, 
        // it's impossible for the needle to be found. Return -1.
        if (haystack.length() < needle.length()) {
            return -1;
        }

        // Loop through the haystack to search for the needle.
        // We only go up to (haystack.length() - needle.length()) 
        // because any further would leave too few characters to match the needle.
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            // Extract a substring from haystack starting at index 'i' 
            // with the same length as the needle. If it matches the needle, return 'i'.
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }

        // If the needle is not found in the haystack, return -1.
        return -1;
    }
};
