// Last updated: 1/6/2026, 10:00:39 PM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;

        while (true) {
            unordered_set<int> seen;
            bool hasDuplicate = false;

            for (int num : nums) {
                if (seen.count(num)) {
                    hasDuplicate = true;
                    break;
                }
                seen.insert(num);
            }

            if (!hasDuplicate) break;

            // Remove the first 3 elements (or all if <3)
            int removeCount = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + removeCount);
            operations++;
        }

        return operations;
    }
};
