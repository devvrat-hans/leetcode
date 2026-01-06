// Last updated: 1/6/2026, 10:00:35 PM
class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int summ = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            for(int j = max(0, i - nums[i]); j<=i; j++ ){
                summ += nums[j];
            }
        }
        
    return summ;    
    }
};