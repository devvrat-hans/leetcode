// Last updated: 1/6/2026, 10:00:31 PM
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = INT_MIN;
        int n = nums.size();
        for(int i = 1; i<n; i++){
            if(abs(nums[i-1] - nums[i]) > maxDiff) maxDiff = abs(nums[i-1] - nums[i]);
        }
        if(abs(nums[0] - nums[n-1]) > maxDiff) maxDiff = abs(nums[0] - nums[n-1]);

        return maxDiff;
        
    }
};