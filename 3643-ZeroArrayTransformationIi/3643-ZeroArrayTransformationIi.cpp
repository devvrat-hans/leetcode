// Last updated: 1/6/2026, 10:00:41 PM
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();

        auto isPossible = [&](int limit) {
            vector<int> diff(size + 1, 0);
            
            for (int i = 0; i < limit; i++) {
                int start = queries[i][0], end = queries[i][1], value = queries[i][2];
                diff[start] += value;
                diff[end + 1] -= value;
            }
            
            int currentSum = 0;
            for (int i = 0; i < size; i++) {
                currentSum += diff[i];
                if (currentSum < nums[i]) return false;
            }
            return true;
        };

        if (all_of(nums.begin(), nums.end(), [](int num) { return num == 0; })) return 0;

        int left = 1, right = queries.size();
        if (!isPossible(right)) return -1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isPossible(mid)) right = mid;
            else left = mid + 1;
        }

        return left;
    
    }
};