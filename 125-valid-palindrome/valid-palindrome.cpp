class Solution {
public:
    bool isPalindrome(string s) {
        //taking two pointers
       int start = 0;
       int end = s.size()-1;

       while(start <= end){
           if(!isalnum(s[start])) //checks whether first character is alphanumeric or not if not alphanumeric then start++
           {
               start++; 
               continue;
           }
           if(!isalnum(s[end])) //checks whether last character is alphanumeric or not if not alphanumeric then end--
           {
               end--; 
               continue;
           }
           if(tolower(s[start]) != tolower(s[end]))  //checks lowercase version of start and end
                  return false;

            else{
                start++;
                end--;
            }      
       }
       return true;
    }
};