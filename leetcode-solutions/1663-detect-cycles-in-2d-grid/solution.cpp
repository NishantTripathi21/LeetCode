class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    
    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py, char ch) {
        if (visited[x][y]) return true;
        visited[x][y] = true;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                if (!(nx == px && ny == py) && grid[nx][ny] == ch) {
                    if (dfs(grid, nx, ny, x, y, ch)) return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1, grid[i][j])) return true;
                }
            }
        }
        return false;
    }
};
