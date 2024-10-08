#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths are not equal, they cannot be anagrams
    if (s.size() != t.size()) {
        return false;
    }

    // Use unordered_map to store character frequencies
    unordered_map<char, int> charFrequency;

    // Increment frequency for each character in string 's'
    for (int i = 0; i < s.size(); i++) {
        charFrequency[s[i]]++;  // Increment count of s[i]
    }

    // Decrement frequency for each character in string 't'
    for (int i = 0; i < t.size(); i++) {
        charFrequency[t[i]]--;  // Decrement count of t[i]

        // If frequency becomes negative, strings are not anagrams
        if (charFrequency[t[i]] < 0) {
            return false;
        }
    }

    // Check if all character frequencies are zero
    for (auto it = charFrequency.begin(); it != charFrequency.end(); ++it) {
        if (it->second != 0) {
            return false;
        }
    }

    return true;
    }
};