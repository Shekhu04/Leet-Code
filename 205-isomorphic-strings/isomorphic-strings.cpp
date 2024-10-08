#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> mapST; // Maps characters from s to t
        unordered_map<char, char> mapTS; // Maps characters from t to s

        for (int i = 0; i < s.length(); i++) {
            char original = s[i];
            char replacement = t[i];

            // Check if the mapping from s -> t exists
            if (mapST.find(original) != mapST.end()) {
                if (mapST[original] != replacement) {
                    return false; // Inconsistent mapping
                }
            } else {
                // Check if replacement is already mapped in mapTS
                if (mapTS.find(replacement) != mapTS.end() && mapTS[replacement] != original) {
                    return false;
                }
                // Establish new mappings in both directions
                mapST[original] = replacement;
                mapTS[replacement] = original;
            }
        }

        return true;
    }
};
