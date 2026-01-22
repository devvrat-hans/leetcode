// Last updated: 1/22/2026, 5:44:00 PM
class Solution {
public:
    int timeTakenTwoPoints(vector<int> &a, vector<int> &b){
        int x = abs(a[0]-b[0]);
        int y = abs(a[1]-b[1]);

        int minn = min(x, y);
        int maxx = x+y-minn;

        return maxx;
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0;
        for(int i = 0; i<n-1; i++){
            time+=timeTakenTwoPoints(points[i], points[i+1]);
        }

        return time;
    }
};