// Last updated: 1/6/2026, 10:02:38 PM
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n  = grid.size();
        
        vector<int> row_max(n, 0);
        vector<int> col_max(n, 0);

        int sum = 0; 
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                row_max[i] = max(row_max[i], grid[i][j]);
                col_max[j] = max(col_max[j], grid[i][j]);
            }

        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int new_height = min(row_max[i], col_max[j]);
                sum += (new_height - grid[i][j]);
                grid[i][j] = new_height;
            }

        }
        return sum;

    }
};