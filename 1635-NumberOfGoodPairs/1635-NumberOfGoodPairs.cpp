// Last updated: 1/6/2026, 10:02:10 PM
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;

        int cnt = 0;

        for(int i = 0; i< n ; i++){
            for(int j = 0;j<n; j++){
                if (i<j && nums[i] == nums[j]) cnt++;
            }

        }
        return cnt;
        
    }
};