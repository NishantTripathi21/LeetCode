class Solution {
public:
    void bfs( vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q; // row,col
        q.push({row,col}); 
        visited[row][col] = true;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while( !q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : directions) {
                int newX = x + dx, newY = y + dy;
                if (newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] == '1' && visited[newX][newY]==false) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
    }

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || visited[i][j] == true){
            return;
        }
        visited[i][j] = true;
        dfs(grid, i + 1, j,visited);
        dfs(grid, i - 1, j,visited);
        dfs(grid, i, j + 1,visited);
        dfs(grid, i, j - 1, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for( int i = 0; i< m; i++) {
            for( int j = 0; j< n; j++) {
                if( !visited[i][j] && grid[i][j]=='1') {
                    dfs(grid,i,j,visited);
                    count++;
                }
            }
        }
        return count;
    }
};
