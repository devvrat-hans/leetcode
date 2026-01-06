// Last updated: 1/6/2026, 10:00:44 PM
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> prevCount;
        int cnt = 0, ansCount1 = 0 , ansCount2 = 0;
        for(int i = 0; i<nums.size(); i++){
            cnt+=nums[i];
            prevCount.push_back(cnt);
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                if(prevCount[i] == totalSum - prevCount[i]){
                    ansCount1++;
                }
                if(prevCount[i] == totalSum - prevCount[i] + 1 || prevCount[i] == totalSum - prevCount[i] - 1){
                    ansCount2++;
                }
            }
        }

        return 2*ansCount1+ansCount2;


    }
};