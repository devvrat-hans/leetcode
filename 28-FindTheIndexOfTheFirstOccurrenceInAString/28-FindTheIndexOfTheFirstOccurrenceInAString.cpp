// Last updated: 1/6/2026, 10:03:30 PM
class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = 0, r = 0;

        while(r < haystack.size()){
            if(haystack[r] == needle[l]){
                while(haystack[r] == needle[l] && l<needle.size()){
                    r++;
                    l++;
                }

                if(l == needle.size()) return r-l;
                else{
                    r-=l;
                    l = 0;   
                }
            }

            r++;
        }

        return -1;
    }
};