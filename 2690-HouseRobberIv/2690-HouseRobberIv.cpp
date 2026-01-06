// Last updated: 1/6/2026, 10:01:16 PM
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        
        auto canRob = [&](int x) -> bool {
            int count = 0, prev = -2;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= x && i - prev > 1) {
                    count++;
                    prev = i;
                }
            }
            return count >= k;
        };
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canRob(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        
        return lo;
    }
};
