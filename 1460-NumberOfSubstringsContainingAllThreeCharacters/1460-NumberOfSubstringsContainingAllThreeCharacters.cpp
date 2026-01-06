// Last updated: 1/6/2026, 10:02:17 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), res = 0;
        int count[3] = {0, 0, 0};
        int left = 0;
        for (int right = 0; right < n; ++right) {
            count[s[right] - 'a']++;
            while (count[0] && count[1] && count[2]) {
                res += n - right;
                count[s[left] - 'a']--;
                left++;
            }
        }
        return res;
    }
};
