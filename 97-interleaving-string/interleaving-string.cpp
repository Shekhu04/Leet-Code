class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if((len1 + len2) != len3){
            return false;
        }
        vector<vector<bool>> indxState(len1+1, vector<bool>(len2+1, false));
        indxState[0][0] = true;

        for(int indx1 = 1; indx1<indxState.size(); indx1++){
            indxState[indx1][0] = indxState[indx1-1][0] && (s1[indx1-1] == s3[indx1-1]); 
        }
        for(int indx2 = 1; indx2<indxState[0].size(); indx2++){
            indxState[0][indx2] = indxState[0][indx2-1] && (s2[indx2-1] == s3[indx2-1]);
        }
        for(int indx1 = 1; indx1<indxState.size(); indx1++){
            for(int indx2 = 1; indx2<indxState[0].size(); indx2++){
                indxState[indx1][indx2] = (indxState[indx1-1][indx2] && s1[indx1-1] == s3[indx1+indx2-1]) || (indxState[indx1][indx2-1] && s2[indx2-1] == s3[indx1+indx2-1]); 
            }
        }
        return indxState[len1][len2];
    }
};