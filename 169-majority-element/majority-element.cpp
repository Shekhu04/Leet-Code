class Solution {
public:
    int majorityElement(vector<int>& arr) {
       int cnt = 0;
       int Element;
       int n = arr.size();

       for(int i=0; i < n; i++){
        if(cnt == 0){
            cnt = 1;
            Element = arr[i];
        }
        else if(arr[i] == Element){
            cnt++;
        }
        else cnt--;
       }
       return Element;
    }
}; 