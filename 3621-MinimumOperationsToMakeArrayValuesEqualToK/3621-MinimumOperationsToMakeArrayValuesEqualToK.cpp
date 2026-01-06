// Last updated: 1/6/2026, 10:00:42 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());

        if(k > mini) return -1;

        map<int, int> mpp;
        for(int i = 0; i<n; i++){
            if(nums[i] != k) mpp[nums[i]]++;
        }

        return mpp.size();
    }
};