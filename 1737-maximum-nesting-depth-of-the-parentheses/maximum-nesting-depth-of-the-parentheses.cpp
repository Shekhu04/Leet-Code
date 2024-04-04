class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int max_num = 0;

        for(char c : s){
            if(c == '('){
                 count ++;
                 if(max_num < count) max_num = count;
            }
            else if(c == ')') count--;

        }
        return max_num;
    }
};

// ex: 1.(1)+((2))+(((3)))
// ind=0 ->count=1,max=1.
// ind=1 ->count=1,max=1.
// ind=2 ->count=0,max=1.
// ind=3 ->count=0,max=1.
// ind=4 ->count=1,max=1.
// ind=5 ->count=2,max=2.
// ind=6 ->count=2,max=2.
// ind=7 ->count=1,max=2.
// ind=8 ->count=0,max=2.
// ind=9 ->count=0,max=2.
// ind=10 ->count=1,max=2.
// ind=11 ->count=2,max=2.
// ind=12 ->count=3,max=3.
// ind=13 ->count=3,max=3.
// ind=14 ->count=2,max=3.
// ind=15 ->count=1,max=3.
// ind=16 ->count=0,max=3.
// thus the max=3.