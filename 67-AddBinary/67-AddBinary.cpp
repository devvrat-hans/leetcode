// Last updated: 1/6/2026, 10:03:13 PM
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length() - 1;
        int n = b.length() - 1;
        int carry = 0;
        string result = "";

        while (m >= 0 || n >= 0 || carry) {
            int sum = carry;

            if (m >= 0) sum += a[m--] - '0'; 
            if (n >= 0) sum += b[n--] - '0'; 

            result += (sum % 2) + '0'; 
            carry = sum / 2;        
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
