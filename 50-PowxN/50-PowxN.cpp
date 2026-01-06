// Last updated: 1/6/2026, 10:03:24 PM
class Solution {
public:
    double power(double base, long long exp){
        double res = 1;
        if(exp < 0){
            exp = -exp;
            base = 1/base;
        }
        while(exp > 0){
            if(exp%2 == 1){
            res*= base;
            }

            base = base*base;
            exp /= 2;
        }
        
        return res;
    }
    double myPow(double x, int n) {
        return power(x, n);
        
    }
};