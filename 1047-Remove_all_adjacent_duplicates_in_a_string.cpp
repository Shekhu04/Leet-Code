string removeDuplicates(string s) {
        string res;
        
        for(char ch : s){
            if(!res.empty() && res[res.size() - 1] == ch) res.pop_back();
            else res+=ch;
        }
        return res;
    }
