class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1; // whichever range reaches '1' first, that will be closest
                    q.push({nr, nc});
                }
            }
        }
        return dist;
    }
};
