// Last updated: 1/6/2026, 10:01:54 PM
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minAbsVal = INT_MAX, negEqCnt = 0;
        long long totalSum = 0;
        int n = matrix.size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int val = matrix[i][j];
                totalSum += abs(val);
                minAbsVal = min(minAbsVal, abs(val));

                if(val <= 0){
                    negEqCnt++;
                }
            }
        }

        if(negEqCnt%2 == 0) return totalSum;
        else return totalSum - 2*minAbsVal;
    }
};