class Solution {
public:
    const int MOD = 1e9 + 7;  // Define a large prime modulus

    long long myPow(long long x, long long n) {
        long long ans = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                ans = (ans * x) % MOD; // Apply modulus to prevent overflow
            }
            x = (x * x) % MOD; // Square x and apply modulus
            n /= 2;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = n / 2 + n % 2;
        return (myPow(5, even) * myPow(4, odd)) % MOD;
    }
};
