// Last updated: 1/6/2026, 10:01:27 PM
class UnionFind {
public:
    vector<int> parent, size;
    UnionFind(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find(int a) {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a]);
    }
    
    void unionn(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int total = m * n;
        
        vector<tuple<int, int, int>> cells;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cells.push_back({grid[i][j], i, j});
            }
        }
        sort(cells.begin(), cells.end());
        
        int k = queries.size();
        // Sort queries along with their original indices
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < k; i++){
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        
        vector<int> ans(k, 0);
        UnionFind uf(total);
        vector<bool> activated(total, false);
        
        auto index = [&](int i, int j) {
            return i * n + j;
        };
        
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int idx = 0;
        for (auto& q : sortedQueries) {
            int queryVal = q.first;
            int qIdx = q.second;
            while (idx < cells.size() && get<0>(cells[idx]) < queryVal) {
                int val, i, j;
                tie(val, i, j) = cells[idx++];
                int cur = index(i, j);
                activated[cur] = true;
                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        int nidx = index(ni, nj);
                        if (activated[nidx])
                            uf.unionn(cur, nidx);
                    }
                }
            }
            if (activated[0]) {
                int root = uf.find(0);
                ans[qIdx] = uf.size[root];
            } else {
                ans[qIdx] = 0;
            }
        }
        
        return ans;
    }
};
