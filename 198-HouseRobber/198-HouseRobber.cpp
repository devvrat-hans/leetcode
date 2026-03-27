// Last updated: 3/27/2026, 5:27:11 PM
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int prev2 = nums[0];
        int prev = max(nums[0],nums[1]); 
        int curr;

        for(int i = 2; i<n; i++){
            int pick = nums[i] + prev2;
            int nonPick = prev;

            curr = max(pick, nonPick);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};