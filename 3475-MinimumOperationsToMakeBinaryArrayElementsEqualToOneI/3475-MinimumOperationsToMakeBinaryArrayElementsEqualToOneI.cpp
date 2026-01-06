// Last updated: 1/6/2026, 10:00:51 PM
class Solution {
public:
    void flip(int &n){
        if(n == 1) n = 0;
        else n = 1;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i<n-2; i++){
            if (nums[i] == 0){
                flip(nums[i]);
                flip(nums[i+1]);
                flip(nums[i+2]);
                cnt++;
            }
            
        }

        if(nums[n-2] == 1 && nums[n-1] == 1) return cnt;
        else return -1;
        
    }
};