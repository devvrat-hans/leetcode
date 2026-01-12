// Last updated: 1/12/2026, 9:23:24 AM
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int row = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[row][mid]) row = i;
            }

            int left  = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 <  m) ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right)
                return {row, mid};

            if (right > mat[row][mid])
                low = mid + 1; 
            else
                high = mid - 1; 
        }

        return {-1, -1};
    }
};
