class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        char choices[] = { 'A', 'C', 'G', 'T' };
        
        unordered_set<string> genes(bank.begin(), bank.end());
        if (genes.find(endGene) == genes.end())
            return -1;

        queue<string> Q;
        Q.emplace(startGene);
        int mutations = 0;

        while (!Q.empty()) {
            size_t size = Q.size();
            for (int i = 0; i < size; i++) {
                string word = Q.front(); Q.pop();
                if (word == endGene)
                    return mutations;

                for (int j = 0; j < 8; j++) {
                    char c = word[j];
                    for (int k = 0; k < 4; k++) {
                        word[j] = choices[k];
                        if (genes.find(word) != genes.end()) {
                            genes.erase(word);
                            Q.emplace(word);
                        }
                    }
                    word[j] = c;
                }
            }
            mutations++;
        }

        return -1;
    }
};