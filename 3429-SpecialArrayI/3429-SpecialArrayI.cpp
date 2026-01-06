// Last updated: 1/6/2026, 10:00:55 PM
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;

        for(int i = 1; i<n; i++){
            if((nums[i]%2 == 1 && nums[i-1]%2 == 0) || (nums[i]%2 == 0 && nums[i-1]%2 == 1)) continue;
            else return false; 
        }

        return true;
    }
};