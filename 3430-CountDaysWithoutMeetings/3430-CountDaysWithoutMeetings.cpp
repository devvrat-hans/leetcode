// Last updated: 1/6/2026, 10:00:53 PM
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;
        
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<vector<int>> merged;
        merged.push_back(meetings[0]);
        for (int i = 1; i < meetings.size(); i++) {
            int currentStart = meetings[i][0], currentEnd = meetings[i][1];
            int &lastStart = merged.back()[0], &lastEnd = merged.back()[1];
            
            if (currentStart <= lastEnd + 1) { 
                lastEnd = max(lastEnd, currentEnd);
            } else {
                merged.push_back(meetings[i]);
            }
        }
        
        long long coveredDays = 0;
        for (auto& interval : merged) {
            int start = max(interval[0], 1);
            int end = min(interval[1], days);
            if (start <= end) {
                coveredDays += (long long)(end - start + 1);
            }
        }
        
        return max(0LL, (long long)days - coveredDays);
    }
};
