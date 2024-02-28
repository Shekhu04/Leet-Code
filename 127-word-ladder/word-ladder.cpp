class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Convert wordList to unordered_set for faster lookup
        unordered_set<string> dict;
        for (int i = 0; i < wordList.size(); i++) {
            dict.insert(wordList[i]);
        }
        
        // Initialize queue for BFS traversal
        queue<string> q;
        q.push(beginWord);
        
        // Initialize result to track transformation length
        int result = 1;
        
        // Perform BFS
        while (!q.empty()) {
            // Get current level count
            int count = q.size();
            
            // Iterate through words at the current level
            for (int i = 0; i < count; i++) {
                string word = q.front();
                q.pop();
                
                // If word is equal to endWord, return result
                if (word == endWord) {
                    return result;
                }
                // Erase word from dictionary
                dict.erase(word);
                
                // Explore neighbors by changing each character
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = k + 'a';
                        // If neighbor exists in dictionary, push to queue
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                            dict.erase(word);
                        }
                        // Restore original character
                        word[j] = c;
                    }
                }
            }
            
            // Increment result for next level
            result++;
        }
        
        // If endWord not found, return 0
        return 0;
    }
};