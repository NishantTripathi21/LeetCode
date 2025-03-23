class Solution {
public:
    int MOD= (int)1e9+7;
    int dijkstra(int n, vector<vector<pair<int,int>>>& adj) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        minHeap.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while(!minHeap.empty()) {
            auto [time, node] = minHeap.top();
            minHeap.pop();
            if (time > dist[node]) continue;
            for (auto [nbr, wt] : adj[node]) {
                long long newTime = (long long)time+wt;
                if (newTime < dist[nbr]) {
                    dist[nbr] =(long long) newTime;
                    minHeap.push({dist[nbr], nbr});
                    ways[nbr] = ways[node];
                } 
                else if (newTime == dist[nbr]) {
                    ways[nbr] = (ways[nbr] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1] %MOD;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i= 0; i< roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u, wt});
        }
        return dijkstra(n,adj);
    }
};
