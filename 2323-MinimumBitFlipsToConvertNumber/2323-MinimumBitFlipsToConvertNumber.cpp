// Last updated: 1/6/2026, 10:01:42 PM
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start ^ goal;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp&(temp-1);
        }

        return cnt;
    }
};