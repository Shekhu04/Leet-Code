class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int element =arr[0];
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(count==0)element=arr[i];
            count+=(element==arr[i])?1:-1;
        }
        return element;
    }
}; 