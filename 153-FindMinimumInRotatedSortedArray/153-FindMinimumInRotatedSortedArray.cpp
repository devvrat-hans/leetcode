// Last updated: 1/6/2026, 10:02:56 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;

        int low = 0, high = n-1;

        while(low<= high){
            int mid = low + (high - low)/2;
            if(nums[low] <= nums[mid]){
                mini = min(nums[low], mini);
                low = mid + 1;
            }
            else{
                mini = min(nums[mid], mini);
                high = mid-1;
            } 
        }

        return mini;

    }
};