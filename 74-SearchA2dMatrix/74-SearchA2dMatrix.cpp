// Last updated: 1/12/2026, 9:24:01 AM
class Solution {
public:

    int myMatrix(int mid, vector<vector<int>> &matrix, int n, int m){
        int i = mid/m;
        int j = mid%m;

        return matrix[i][j];
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = n*m-1;

        while(low <= high){
            int mid = low + ((high - low) >> 1);

            if(myMatrix(mid, matrix, n, m) == target) return true;
            else if(myMatrix(mid, matrix, n, m) < target) low = mid+1;
            else high = mid - 1;
        }

        return false;
    }
};