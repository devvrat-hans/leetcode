// Last updated: 1/6/2026, 10:03:09 PM
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;

        int curr, prev = 0, prev2 = 1;
        for(int i =0; i<=n; i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return curr;
    }
};