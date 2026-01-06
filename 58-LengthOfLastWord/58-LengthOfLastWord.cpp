// Last updated: 1/6/2026, 10:03:18 PM
class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        
        int cnt = 0;
        bool wordStart = false;
        
        for(char ch: s){
            if(ch == ' ' && !wordStart) continue;
            if(ch == ' '){
                break;
            }
            else{
                wordStart = true;
                cnt++;
            }
        }

        return cnt;
    }
};