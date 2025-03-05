class Solution {
public:
    int bfs(vector<vector<int>>& adj) {
        int n = adj.size();
        int shortest = INT_MAX;
        for (int start = 0; start < n; start++) {
            vector<int> dist(n, -1);
            queue<pair<int, int>> q;  // {node, parent}
            dist[start] = 0;
            q.push({start, -1});
            while (!q.empty()) {
                auto [node, parent] = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (dist[neighbor] == -1) {  // unvisited
                        dist[neighbor] = dist[node] + 1;
                        q.push({neighbor, node});
                    }
                    else if (neighbor != parent) {
                        // cycle
                        shortest = min(shortest, dist[node] + dist[neighbor] + 1);
                    }
                }
            }
        }
        
        return shortest == INT_MAX ? -1 : shortest;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // dfs will not work here 
        int minSize = INT_MAX;
        vector<vector<int>>adj(n);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return bfs(adj);
    }
};
