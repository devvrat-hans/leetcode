// Last updated: 1/6/2026, 10:02:42 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        int sum = 0, cnt = 0;
        
        mp[0] = 1; 
        for (int num : nums) {
            sum += num; 

            if (mp.find(sum - k) != mp.end()) { 
                cnt += mp[sum - k]; 
            }

            mp[sum]++; 
        }

        return cnt;
    }
};
