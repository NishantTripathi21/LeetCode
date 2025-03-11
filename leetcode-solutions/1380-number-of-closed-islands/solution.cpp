class Solution {
public:
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    int n;
    int m;
    void dfs(vector<vector<int>>& grid, int row, int col) {
        grid[row][col] = 1;
        for(auto [dx,dy]: directions) {
            int nr = row + dx;
            int nc = col + dy;
            if(nr < n && nr >= 0 && nc < m && nc >= 0 && grid[nr][nc] == 0) {
                dfs(grid,nr,nc);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m = grid[0].size();
        for(int i= 0; i< n; i++) {
            if(grid[i][0] == 0) {
                dfs(grid,i,0);
            }
            if(grid[i][m-1] == 0) {
                dfs(grid,i,m-1);
            }
        }
        for(int i= 0; i< m; i++) {
            if(grid[0][i] == 0) {
                dfs(grid,0,i);
            }
            if(grid[n-1][i] == 0) {
                dfs(grid,n-1,i);
            }
        }
        int count = 0;
        for(int i= 0; i< n; i++) {
            for(int j= 0; j< m; j++) {
                if(grid[i][j] == 0) {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
