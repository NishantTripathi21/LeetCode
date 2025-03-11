class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; //{cost,row,col}
        // Directions: right (1), left (2), down (3), up (4)
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        
        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();
            if (x == m - 1 && y == n - 1) return cost;
            if (cost > dist[x][y]) continue;
            for (int d = 0; d < 4; ++d) {
                int nx = x + directions[d].first, ny = y + directions[d].second;
                int newCost = (d + 1 == grid[x][y]) ? 0 : 1;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && cost + newCost < dist[nx][ny]) {
                    dist[nx][ny] = cost + newCost;
                    pq.push({dist[nx][ny], nx, ny});
                }
            }
        }
        return -1;
    }
};
