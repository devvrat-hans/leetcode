// Last updated: 1/6/2026, 10:01:59 PM
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int summ = 0;

        for(int i = 0; i<(1<<n); i++){ 
            int xorr = 0;
            for(int j = 0; j<n; j++){
                if(i&(1 << j)) xorr^=nums[j]; 
            }
            summ += xorr;
        }

        return summ;
    }
};