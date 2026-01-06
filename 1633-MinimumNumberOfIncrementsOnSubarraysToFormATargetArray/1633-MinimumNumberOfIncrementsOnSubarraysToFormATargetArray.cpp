// Last updated: 1/6/2026, 10:02:11 PM
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int operations = target[0]; 

        for (int i = 1; i < n; i++) {
            if (target[i] > target[i - 1]) {
                operations += target[i] - target[i - 1];
            }
        }

        return operations;
    }
};
