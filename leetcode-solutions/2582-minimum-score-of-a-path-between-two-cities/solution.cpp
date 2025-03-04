class Solution {
public:
    int bfs(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto road : roads) {
            int a = road[0], b = road[1], distance = road[2];
            graph[a].push_back({b, distance});
            graph[b].push_back({a, distance});
        }

        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int min_score = INT_MAX;
        while (!q.empty()) {
            int city = q.front();
            q.pop();
            for (auto nbr : graph[city]) {
                int next_city = nbr.first;
                int dist = nbr.second;
                min_score = min(min_score, dist);
                if (!visited[next_city]) {
                    visited[next_city] = true;
                    q.push(next_city);
                }
            }
        }

        return min_score;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        return bfs(n,roads);
    }
};
