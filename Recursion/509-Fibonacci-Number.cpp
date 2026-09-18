class Solution {
public:
    // int fib(int n) {
    //     int memo[100];
    //     if (n == 0 or n == 1) return n;
    //     if (memo[n] != 0) return memo[n];
    //     return memo[n] = fib(n-1) + fib(n-2);
    // }







    int fib(int n) {
        if (n == 0 or n == 1) return n;
        return fib(n-1) + fib(n-2);
    } //Time Complexity = O(2^n)
};
