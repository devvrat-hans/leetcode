// Last updated: 1/6/2026, 10:03:05 PM
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i<(1<<n); i++){
            vector<int> list1;
            for(int j = 0; j<n; j++){
                if(i&(1 << j)) list1.push_back(nums[j]);
            }

            ans.push_back(list1);
        }

        return ans;
    }
};