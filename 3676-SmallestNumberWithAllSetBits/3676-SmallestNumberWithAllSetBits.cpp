// Last updated: 1/6/2026, 10:00:27 PM
class Solution {
public:
    int smallestNumber(int n) {
        int digitCount = 0;
        int a = n;
        while(a){
            a >>= 1;
            digitCount++;
        }

        return pow(2, digitCount) - 1;
    }
};