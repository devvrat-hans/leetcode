// Last updated: 1/6/2026, 10:02:28 PM
class Solution {
public:
    int fib(int n) {
        if (n==0) return 0;
        if (n ==1) return 1;

        return fib(n-1) + fib(n-2);

    }
};