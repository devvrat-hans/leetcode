// Last updated: 1/6/2026, 10:01:02 PM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> hash(n*n+1, 0);
        
        int a, b;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                hash[grid[i][j]]++;
                if (hash[grid[i][j]] == 2) a = grid[i][j];
            }
        }

        for(int i = 1; i<n*n+1; i++){
            if(hash[i] == 0){
                b = i;
                break;
            }
        }

        return {a, b};
    }
};