// Last updated: 1/6/2026, 10:01:38 PM
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int wcnt = 0;

        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') wcnt++;
        }

        int minops = wcnt;

        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') wcnt++;     
            if (blocks[i - k] == 'W') wcnt--;

            minops = min(minops, wcnt);
        }

        return minops;
    }
};