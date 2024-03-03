/* 1.Iterate over the string and check
2. If there are characters assign them to temp and move forward
3. If space is encountered then break from above loop
4. Now check if temp size>0
5. If ans size is 0 then assign temp to the ans
    else do ans = temp+" "+ans
6.If space is encountered just move the pointer forward */

class Solution {
    public:
    string reverseWords(string s) 
    {
        int n = s.size();
        int i = 0;
        string ans="";

        while(i<n){
            string temp="";
            while(s[i]==' ' && i<n)
               i++;
            while(s[i] !=' ' && i<n){
                temp += s[i];
               i++;
            }
            if(temp.size()>0)
            {
                if(ans.size() == 0)
                   ans = temp;
                   else
                   ans = temp+" "+ans;
            }
              
        }
        return ans;
    }
};