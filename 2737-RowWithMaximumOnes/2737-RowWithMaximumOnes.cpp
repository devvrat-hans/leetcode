// Last updated: 1/9/2026, 10:07:34 PM
class Solution {
public:
    int upperBound(vector<int> &arr, int k){
        int m = arr.size();
        int low = 0, high = m - 1;

        sort(arr.begin(), arr.end());

        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(arr[mid] <= k) low = mid + 1;
            else high = mid - 1;
        }

        return high + 1;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxCnt = 0;
        int rowIdx = 0;

        for(int i = 0; i < n; i++){
            int zeros = upperBound(mat[i], 0);
            int ones = m - zeros;

            if(ones > maxCnt){
                maxCnt = ones;
                rowIdx = i;
            }
        }

        return {rowIdx, maxCnt};
    }
};