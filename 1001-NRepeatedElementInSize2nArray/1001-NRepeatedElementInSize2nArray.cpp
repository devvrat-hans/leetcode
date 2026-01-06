// Last updated: 1/6/2026, 10:02:32 PM
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size()/2;
        sort(nums.begin(), nums.end());

        if(nums[n-1] == nums[0]) return nums[0];
        else if(nums[n] == nums[2*n-1]) return nums[2*n-1];
        else return nums[n];
    }
};