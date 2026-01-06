// Last updated: 1/6/2026, 10:03:22 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxx = INT_MIN, summ = 0;

        for(int i = 0; i<n; i++){
            summ += nums[i];

            if(summ > maxx){
                maxx = summ;
            }

            if(summ < 0) summ = 0;     
        }

        return maxx;
        
    }
};