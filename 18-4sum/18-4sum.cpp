// Last updated: 1/6/2026, 10:03:38 PM
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;

        for(int i = 0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j<n; j++){
                if(j!=i+1 && nums[j] == nums[j - 1]) continue;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long summ = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(summ == target){
                        vector<int>temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++; l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] == nums[l+1]) l--;
                    }
                    else if(summ < target)k++;
                    else l--;
                }
            }
        }

        return ans;
    }
};