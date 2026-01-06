// Last updated: 1/6/2026, 10:01:52 PM
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        // Build the graph as an adjacency list: each pair is (neighbor, travel_time)
        vector<vector<pair<int, long long>>> graph(n);
        for (auto &road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        
        // Initialize distance and ways arrays
        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        // Priority queue for Dijkstra's algorithm (min-heap based on distance)
        using pli = pair<long long, int>;
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            // Skip if we have already found a better way to this node.
            if (d > dist[u])
                continue;
            
            // Process each neighbor of u
            for (auto &edge : graph[u]) {
                int v = edge.first;
                long long w = edge.second;
                // Found a shorter path to v
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                // Found another shortest path to v
                else if (d + w == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        
        return ways[n - 1];
    }
};
