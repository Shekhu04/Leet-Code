class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();

        for(int i = 0; i<n; i++){
            map<char,int> m;

            for(int j = i; j < n; j++){
                m[s[j]]++;

                int max_freq = 0;
                int min_freq = INT_MAX;

                for(auto it : m){
                    max_freq = max(max_freq, it.second);
                    min_freq = min(min_freq, it.second);
                }
            ans += (max_freq - min_freq);
            }
        }
        return ans;
    }
};