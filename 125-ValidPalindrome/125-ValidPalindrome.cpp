// Last updated: 1/6/2026, 10:03:00 PM
class Solution {
public:
    bool isPalindrome(string s) {
        string res;

        for (char c : s){
            if (isalnum(c)) res+= tolower(c);
        }

        int n = res.length();

        for(int i = 0,j = n-1; i<=j ; i++,j--){
            if (res[i] != res[j]) return false;
            
        }
        return true;
        
    }
};