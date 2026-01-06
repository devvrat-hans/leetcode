// Last updated: 1/6/2026, 10:01:34 PM
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, mask = 0, max_len = 0;

        for (int right = 0; right < n; ++right) {
            while ((mask & nums[right]) != 0) {
                mask ^= nums[left]; 
                left++;
            }
            mask |= nums[right];
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};
