class Solution {
public:
    double myPow(double x, int n) {
        
       double ans = 1; // Initialize the result variable to 1
       long long num = n; // Use a long long to handle the case where n is INT_MIN

       // If n is negative, convert it to positive
       if (num < 0) num = -1 * num;

       // Iterate until num becomes 0
       while(num){
           // If num is odd, multiply the result by x
           if(num % 2){
               ans = ans * x;
               num = num - 1;
           }
           // If num is even, square x and divide num by 2
           else{
               x = x * x;
               num = num / 2;
           }
       }

       // If the original n was negative, invert the result
       if (n < 0) ans = (double)(1) / (double)(ans);

       return ans; // Return the final result
    }
};
