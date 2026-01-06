// Last updated: 1/6/2026, 10:00:33 PM
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return {};
        int cols = grid[0].size();
        
        vector <int> res;
        
        for(int i = 0; i<rows; i++){
            if(i%2 == 0){
                for(int j = 0; j<cols; j++){
                    if(i%2 == j%2){
                        res.push_back(grid[i][j]);
                    }
                }  
            }
            else{
                for(int j = cols - 1; j>=0; j--){
                    if(i%2 == j%2){
                        res.push_back(grid[i][j]);
                    }
                }
            }
            
            
            
            
        }
        return res;
    }
};