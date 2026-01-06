// Last updated: 1/6/2026, 10:01:22 PM
class Solution {
public:
    long long coloredCells(int n) {
        long long N = n; 
        return (2 * N * (N - 1) + 1);
    }
};
