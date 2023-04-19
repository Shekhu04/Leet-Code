class Solution {
public:
    bool isPerfectSquare(int num) {
    if(num==1||num==4)
        return true;
    else
    {
        int s=0;
        int e=num;
        while(s<=e)
        {
            long long int mid=s+(e-s)/2;
            if(mid*mid==num)
                return true;
            else if(mid*mid>num)
                e=mid-1;
            else if(mid*mid<num)
                s=mid+1;
        }
    }
    return false;

    }
};
