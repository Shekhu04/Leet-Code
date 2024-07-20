#include <unordered_map>
#include <string>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        // Use unordered_map to store character frequencies
        unordered_map<char, int> charFrequency;

        // Increment frequency for each character in string s
        for (char c : s) {
            charFrequency[c]++;
        }

        // Decrement frequency for each character in string t
        for (char c : t) {
            charFrequency[c]--;

            // If frequency becomes negative, strings are not anagrams
            if (charFrequency[c] < 0) {
                return false;
            }
        }

        // Check if all character frequencies are zero
        for (const auto& pair : charFrequency) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;
    }
};