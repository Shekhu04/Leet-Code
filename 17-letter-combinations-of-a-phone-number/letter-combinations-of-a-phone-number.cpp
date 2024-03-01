class Solution {
public:
    vector<string> hap{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void help(string input,string output,int k){
        if(input.size()==k ){
            ans.push_back(output);
            return;
        }
        //base
        for(int i=0;i<hap[input[k]-50].size();i++){
            output.push_back(hap[input[k]-50][i]);
            help(input,output,k+1);
            output.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return ans;
        string output;
        help(digits,output,0);
        return ans;
    }
};