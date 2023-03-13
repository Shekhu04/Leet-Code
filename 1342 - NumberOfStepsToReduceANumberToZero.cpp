class Solution {
public:
    int numberOfSteps(int num) {
        if(num<=1)
        { 
        return num;
        }
        int count=0;
        if(num%2==0){
       count += numberOfSteps(num/2)+1;
    }
    else{
        count += numberOfSteps(num-1)+1;
    }
    return count;
    }
        
};
