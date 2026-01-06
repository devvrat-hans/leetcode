// Last updated: 1/6/2026, 10:02:53 PM
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        if (n1 != n2) return false;

        vector<int> hash(26, 0);  

        for (int i = 0; i < n1; i++) {
            hash[s[i] - 'a']++;
            hash[t[i] - 'a']--; 
        }

        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0) return false;
        }

        return true;
    }
};
