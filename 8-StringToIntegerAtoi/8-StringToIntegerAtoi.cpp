// Last updated: 1/6/2026, 10:03:47 PM
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        while (i < n && s[i] == ' ') i++;

        bool neg = false;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') neg = true;
            i++;
        }

        int res = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (res > (INT_MAX - digit) / 10) {
                return neg ? INT_MIN : INT_MAX;
            }

            res = res * 10 + digit;
            i++;
        }

        return neg ? -res : res;
    }
};