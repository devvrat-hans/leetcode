// Last updated: 1/6/2026, 10:01:56 PM
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();
        for(int i = 0; i<2*n; i++){
            arr.emplace_back(nums[i%n]);
        }

        return arr;
        
        
    }
};