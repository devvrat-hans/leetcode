// Last updated: 1/6/2026, 10:00:58 PM
class UnionFind {
public:
    vector<int> parent, size;
    
    UnionFind(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if(pa == pb)
            return false;
        if(size[pa] < size[pb])
            swap(pa, pb);
        parent[pb] = pa;
        size[pa] += size[pb];
        return true;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> g(n, -1);
        UnionFind uf(n);
        
        for(auto &e : edges){
            uf.unite(e[0], e[1]);
        }
        
        for(auto &e : edges){
            int root = uf.find(e[0]);
            g[root] &= e[2];
        }
        
        vector<int> ans;
        for(auto &q : query){
            int u = q[0], v = q[1];
            if(u == v) {
                ans.push_back(0);
            } else if(uf.find(u) == uf.find(v)){
                ans.push_back(g[uf.find(u)]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
