// Last updated: 1/6/2026, 10:03:17 PM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        vector<vector<int>> ans;

        for(int i = 1; i<n; i++){
            if(intervals[i][0] <= end){
                if(end<intervals[i][1]){
                    end = intervals[i][1];
                }
                
            }
            else{
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};