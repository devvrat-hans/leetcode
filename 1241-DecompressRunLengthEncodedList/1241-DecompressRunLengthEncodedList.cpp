// Last updated: 1/6/2026, 10:02:23 PM
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            if (i%2 == 0){
                for(int j = 0; j< nums[i]; j++){
                    res.push_back(nums[i+1]);
                }
                
            }
                
        }
        return res;

        
    }
};