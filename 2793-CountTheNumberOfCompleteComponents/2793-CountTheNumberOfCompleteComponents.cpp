// Last updated: 1/6/2026, 10:01:11 PM
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        int completeCount = 0;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                vector<int> compNodes;
                int edgeCount = 0;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    compNodes.push_back(curr);
                    edgeCount += graph[curr].size();
                    for(auto nb : graph[curr]){
                        if(!visited[nb]){
                            visited[nb] = true;
                            q.push(nb);
                        }
                    }
                }
                int m = compNodes.size();
                int actualEdges = edgeCount / 2;
                if(actualEdges == m*(m-1)/2) {
                    completeCount++;
                }
            }
        }
        
        return completeCount;
    }
};
