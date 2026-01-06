// Last updated: 1/6/2026, 10:03:50 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0, right = 0;
        int max_count = 0;

        while(right < n){
            for(int i = left; i<right; i++){
                if(s[right] == s[i]){
                    left=(i+1);
                    break;
                }
            }
            max_count = max(max_count, right-left+1);
            right++;
        }

        return max_count;

    }
};