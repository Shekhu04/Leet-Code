class Solution {
public:
    bool rotateString(string s, string goal) {
    int n = s.length();  // Length of the string 's'
    int m = goal.length();  // Length of the string 'goal'
    int i = 0;  // Counter to keep track of number of rotations

    // If the lengths of 's' and 'goal' are not the same, they cannot be rotations of each other
    if (m != n) {
        return false;
    }

    // Try rotating the string 's' n times
    while (i < n) {
        // If 's' matches 'goal', return true
        if (s == goal) {
            return true;
        }

        // Save the first character of 's'
        char firstChar = s[0];

        // Shift all characters of 's' one position to the left
        for (int j = 0; j < n - 1; j++) {
            s[j] = s[j + 1];
        }

        // Place the first character at the end of the string
        s[n - 1] = firstChar;

        // Increment the counter
        i++;
    }

    // If no rotation of 's' matches 'goal', return false
    return false;
    }
};