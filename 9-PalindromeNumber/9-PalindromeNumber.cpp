// Last updated: 1/6/2026, 10:03:45 PM
class Solution {
public:
    bool isPalindrome(int x) {
        // if (x < 0 || (x % 10 == 0 && x != 0)) {
        //     return false;
        // }

        // int rev = 0;
        // int n = x;

        // while (n != 0) {
        //     int last_digit = n % 10;

        //     if (rev > (INT_MAX / 10) || (rev == (INT_MAX / 10) && last_digit > 7)) {
        //         return false;
        //     }

        //     rev = rev * 10 + last_digit;
        //     n /= 10;
        // }

        // return rev == x;
        string str = to_string(x);
        for (int i = 0, j = str.length() - 1; i<j; i++, j--){
            if (str[i] != str[j]){
                return false;
            }
        }
        return true;

    }
};
