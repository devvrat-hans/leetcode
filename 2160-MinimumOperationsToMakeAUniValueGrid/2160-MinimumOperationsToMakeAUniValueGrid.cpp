// Last updated: 1/6/2026, 10:01:50 PM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (const auto &row : grid) {
            for (int num : row) {
                nums.push_back(num);
            }
        }
        
        int remainder = nums[0] % x;
        for (int num : nums) {
            if (num % x != remainder)
                return -1; 
        }
        
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        long long operations = 0;
        
        for (int num : nums) {
            operations += abs(num - median) / x;
        }
        
        return operations;
    }
};
