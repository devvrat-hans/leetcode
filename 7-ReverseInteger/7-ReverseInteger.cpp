// Last updated: 1/6/2026, 10:03:48 PM
class Solution {
public:
    int reverse(int x) {
        int last_digit = 0;
        int rev = 0;
        int a = x;

        while(a!=0){
            last_digit = a%10;
            a/=10;
            if (rev > (INT_MAX) / 10 || rev<(INT_MIN)/10) {
                return 0; 
            }
            
            rev = rev*10 + last_digit;

        }
        return rev;
            
    }

    
};