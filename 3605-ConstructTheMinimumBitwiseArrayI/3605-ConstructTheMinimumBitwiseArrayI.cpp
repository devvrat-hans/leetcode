// Last updated: 1/22/2026, 5:43:17 PM
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int n : nums) {
            int best = -1;

            for (int x = 0; x <= n; x++) {
                if ((x | (x + 1)) == n) {
                    best = x;
                    break; // smallest found
                }
            }

            ans.push_back(best);
        }

        return ans;
    }
};
