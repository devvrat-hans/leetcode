// Last updated: 3/27/2026, 5:26:54 PM
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> mimage = image;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int starting_color = image[sr][sc];

        mimage[sr][sc] = color;
        q.push({sr, sc});
        vis[sr][sc] = 1;

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i = 0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m){
                    if(mimage[nrow][ncol] == starting_color && vis[nrow][ncol] == 0){
                        mimage[nrow][ncol] = color;
                        q.push({nrow, ncol});
                        vis[nrow][ncol] = 1;
                    }
                }

            }
        }

        return mimage;

        
    }
};