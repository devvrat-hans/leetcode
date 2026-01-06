// Last updated: 1/6/2026, 10:02:15 PM
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector <int> res;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            int cnt = 0;
            for(int j = 0; j<n; j++){
                if(nums[i]>nums[j]) cnt++;

            }
            res.push_back(cnt);
        }
        return res;
        
    }
};