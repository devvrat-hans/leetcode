// Last updated: 1/6/2026, 10:00:50 PM
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> valid(n);
        for (int i = 0; i < n; i++) {
            valid[i] = (colors[i] != colors[(i + 1) % n]) ? 1 : 0;
        }
        
        int windowSize = k - 1;
        vector<int> valid_ext(n + windowSize);
        for (int i = 0; i < n; i++) {
            valid_ext[i] = valid[i];
        }
        for (int i = 0; i < windowSize; i++) {
            valid_ext[n + i] = valid[i];
        }
        
        int sum = 0;
        for (int i = 0; i < windowSize; i++) {
            sum += valid_ext[i];
        }
        
        int count = 0;
        if (sum == windowSize) count++; 
        
        for (int i = 1; i < n; i++) {
            sum = sum - valid_ext[i - 1] + valid_ext[i + windowSize - 1];
            if (sum == windowSize) count++;
        }
        
        return count;
    }
};
