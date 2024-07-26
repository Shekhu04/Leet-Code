class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        int n = s.size();

        for(int i=0; i<n; i++){
            
            map<char,int> m;

            for(int j=i; j<n; j++){
                m[s[j]]++;
                int max_freq = 0;
                int least_freq = INT_MAX;

                for(auto a : m){
                    max_freq = max(max_freq, a.second);
                    least_freq = min(least_freq,a.second);
                }
                ans += (max_freq - least_freq);
            }
        }
        return ans;
    }
};