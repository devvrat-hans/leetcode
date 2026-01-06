// Last updated: 1/6/2026, 10:01:18 PM
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;  
        
        vector<long long> costs;
        for (int i = 0; i < n - 1; i++) {
            costs.push_back((long long)weights[i] + weights[i + 1]);
        }
        
        sort(costs.begin(), costs.end());
        
        int splits = k - 1;
        long long minExtra = 0, maxExtra = 0;
        for (int i = 0; i < splits; i++) {
            minExtra += costs[i]; 
            maxExtra += costs[costs.size() - 1 - i];  
        }
        
        return maxExtra - minExtra;
    }
};
