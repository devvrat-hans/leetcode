// Last updated: 1/6/2026, 10:03:43 PM
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> itr = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"},
        };

        string res;

        for(int i = 0; i< itr.size(); i++){
            int quo = num/(itr[i].first);
            for(int j = 0; j< quo; j++) res += itr[i].second;
            num%=itr[i].first;
        }
        
        return res;
    }
};