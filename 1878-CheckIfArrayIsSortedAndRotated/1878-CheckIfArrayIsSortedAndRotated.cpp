// Last updated: 1/6/2026, 10:02:06 PM
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        for(int i = 0; i<n-1;i++){
            if (nums[i]>nums[i+1]) index = i+1;
        }
        if(index == -1) return true;

        for(int i =0; i<n-1; i++){
            if(nums[(i+index)%n] > nums[(i+1+index)%n]) return false;
        }

        return true;
        
    }
};