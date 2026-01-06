// Last updated: 1/6/2026, 10:01:06 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        // Precompute prefix maximums, ensuring that for j we use only indices i < j.
        vector<int> prefixMax(n, 0);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }
        
        // Precompute suffix maximums, ensuring that for j we use only indices k > j.
        vector<int> suffixMax(n, 0);
        suffixMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], nums[i]);
        }
        
        long long res = 0;
        // Loop for each possible middle index j.
        for (int j = 1; j < n - 1; j++) {
            // Since i must be less than j, use prefixMax[j - 1].
            long long diff = (long long)prefixMax[j - 1] - nums[j];
            // Since k must be greater than j, use suffixMax[j + 1].
            long long candidate = diff * suffixMax[j + 1];
            res = max(res, candidate);
        }
        return res;
    }
};
