// Last updated: 1/6/2026, 10:03:20 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_len = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(i > max_len) return false;
            max_len = max(max_len, nums[i] + i);
        }

        return true;
    }
};