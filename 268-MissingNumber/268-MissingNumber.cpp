// Last updated: 1/6/2026, 10:02:51 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>hash(n+1, 0);

        for(int i = 0;i<n;i++){
            hash[nums[i]]++;
        }

        for(int i=0; i<n+1; i++){
            if(hash[i] == 0) return i;
        }
        return n;
    }
};