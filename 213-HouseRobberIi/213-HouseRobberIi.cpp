// Last updated: 3/27/2026, 5:27:08 PM
class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        if(start == end) return nums[start];
        
        int prev2 = nums[start];
        int prev = max(nums[start], nums[start+1]);
        int curr;

        for(int i = start+2; i<=end; i++){
            int pick = nums[i] + prev2;
            int nonPick = prev;

            curr = max(pick, nonPick);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int case1 = robLinear(nums, 0, n-2);
        int case2 = robLinear(nums, 1, n-1);

        return max(case1, case2);
    }
};