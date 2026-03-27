// Last updated: 3/27/2026, 5:26:56 PM
class Solution {
public: 
    void dfs(int node, vector<vector<int>> &adjLs, vector<int> &vis){
        vis[node] = 1;
        for(auto it: adjLs[node]){
            if(!vis[it]){
                dfs(it, adjLs, vis);
            } 
        }
    }

    vector<vector<int>> adjMatrixToList(vector<vector<int>>& adjMatrix){
        int n = adjMatrix.size();
        vector<vector<int>> adjLs(n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(adjMatrix[i][j] == 1){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        return adjLs;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLs = adjMatrixToList(isConnected);
        vector<int> vis(n, 0);
        int cnt = 0;

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, adjLs, vis);
                cnt++;
            }
        }

        return cnt;   
        
    }
};