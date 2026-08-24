class Solution {
public:

    long long power(long long x, long long n) {
        long long ans = 1;
        long long MOD = 1000000007;

        while(n > 0) {

            if(n % 2 == 1) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;
            n = n / 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans1 = power(5, even);
        long long ans2 = power(4, odd);

        return (ans1 * ans2) % 1000000007;
    }
};