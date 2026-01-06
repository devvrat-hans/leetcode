// Last updated: 1/6/2026, 10:03:15 PM
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans = digits;
        int carry = 1; 

        for (int i = n - 1; i >= 0; i--) {
            int sum = ans[i] + carry;
            ans[i] = sum % 10;
            carry = sum / 10;

            if (carry == 0) break;
        }

        if (carry) {
            ans.insert(ans.begin(), carry);
        }

        return ans;
    }
};
