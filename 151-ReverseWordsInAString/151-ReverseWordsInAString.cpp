// Last updated: 1/6/2026, 10:02:58 PM
class Solution {
public:
    string reverseWords(string s) {
        vector<string> a;
        string st = "";

        for(char ch: s){
            if(ch == ' '){
                if(st != "") a.push_back(st);
                st ="";
            }
            else {
                st += ch; 
            }  
            
        }

        if(st != " " && st != "") a.push_back(st);
  
        string res = a[a.size() - 1];

        for(int i = a.size()-2; i>=0; i--){
            res += " " + a[i];
        }

        return res;
        
    }
};