// Last updated: 1/6/2026, 10:03:28 PM
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; 

        bool sign = true;
        if(dividend <= 0 && divisor > 0) sign = false;
        if(dividend >= 0 && divisor < 0) sign = false;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;

        while(n >= d){
            int cnt = 0;
            while(n >= (d << (cnt+1)))cnt++;

            quotient += (1 << cnt);
            n -= (d << cnt);
        }

        if(quotient >= INT_MAX && sign == true) return INT_MAX;
        if(quotient <= INT_MIN && sign == false) return INT_MIN;

        return sign ? quotient : (-1)*quotient; 
    }
};