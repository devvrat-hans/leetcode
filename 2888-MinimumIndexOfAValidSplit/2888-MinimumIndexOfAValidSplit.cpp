// Last updated: 1/6/2026, 10:01:09 PM
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int candidate = -1, count = 0;

        // Step 1: Boyer-Moore Majority Vote Algorithm to find the potential dominant element
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        // Step 2: Verify if the candidate is actually dominant
        int total_count = 0;
        for (int num : nums) {
            if (num == candidate) total_count++;
        }
        
        if (total_count <= n / 2) return -1; // No dominant element

        // Step 3: Find the minimum index where both halves retain dominance
        int left_count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == candidate) left_count++;

            int right_count = total_count - left_count;
            if (left_count > (i + 1) / 2 && right_count > (n - i - 1) / 2) {
                return i;
            }
        }

        return -1;
    }
};
