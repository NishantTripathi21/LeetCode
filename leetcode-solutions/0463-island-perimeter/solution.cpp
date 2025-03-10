class Solution {
public:
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& grid, int row, int col, int& perimeter) {
        int n = grid.size();
        int m = grid[0].size();
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0) {
            perimeter++;
            return;
        }

        if (grid[row][col] == -1) return;
        grid[row][col] = -1;
        for (auto [dx, dy] : directions) {
            int nr = row + dx;
            int nc = col + dy;
            dfs(grid, nr, nc, perimeter);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i= 0; i< n; i++) {
            for(int j= 0; j< m; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid,i,j,perimeter);
                    return perimeter;
                }
            }
        }
        return perimeter;
    }
};
