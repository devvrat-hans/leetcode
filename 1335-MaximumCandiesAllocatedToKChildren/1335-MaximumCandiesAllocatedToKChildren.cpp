// Last updated: 1/6/2026, 10:02:19 PM
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long count = 0;
            for (int candy : candies) {
                count += candy / mid;
            }

            if(count >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
