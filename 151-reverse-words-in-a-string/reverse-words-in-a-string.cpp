class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        istringstream in(s); 
        string word;
        while(in>>word){
            v.push_back(word);
        }
        string ans;
        for(int i=v.size()-1;i>=0;i--){
            if (i != v.size() - 1) ans += " ";
            ans += v[i];
        }
        return ans;
    }
};