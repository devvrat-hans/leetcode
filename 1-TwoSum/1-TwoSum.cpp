// Last updated: 1/6/2026, 10:03:54 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i = 0; i<n; i++){
            int rem = target - nums[i];

            if(mp.find(rem) != mp.end()){
                return {mp[rem], i};
            }

            mp[nums[i]] = i;
        }

        return {0,0};
    }
};