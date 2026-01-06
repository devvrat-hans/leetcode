// Last updated: 1/6/2026, 10:02:44 PM
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0, r = 0;

        while(r < s.size()){
            if(l >= g.size()) break;
            if(g[l] <= s[r]){
                l++;
            }
            r++;
        }

        return l;
    }
};