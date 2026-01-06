// Last updated: 1/6/2026, 10:03:39 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        for (int j = 0; j < strs[0].length(); j++) {
            char check = strs[0][j];
            for (int i = 1; i < strs.size(); i++) {
                if (j >= strs[i].length() || strs[i][j] != check) 
                    return strs[0].substr(0, j);
            }
        }
        return strs[0];
    }
};
