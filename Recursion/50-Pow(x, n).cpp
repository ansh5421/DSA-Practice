class Solution {
public:
    double power(double x, long long n) {
        if (n == 0) return 1;
        double ans = power(x, n/2);
        return (n % 2 == 0) ? ans * ans : ans * ans * x;
    }

    
    double myPow(double x, int n) {
        bool isPos = (n >= 0); // true when n is positive
        long long n2 = n;
        double ans = power(x, abs(n2));
        if (isPos == false) ans = 1/ans;
        return ans;
    }
};
