class Solution {
public:
    int m,n;
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& grid, int k, int x, int y) {
        if(x >= m || y >= n) {
            return -1;
        }
        int cost = (grid[x][y] == 0) ? 0 : 1;
        if(k < cost)return -1;

        if(x == m-1 && y == n-1) {
            return grid[x][y];
        }
         if (dp[x][y][k] != -2) return dp[x][y][k];
        
        int right = solve(grid,k-cost, x, y+1);

        int down = solve(grid,k-cost, x+1, y);

        if(right == -1 && down == -1) {
            return dp[x][y][k] = -1;
        }

        return dp[x][y][k] = max(right,down) + grid[x][y];
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(k + 1, -2))); 
        return solve(grid,k,0,0);
    }
};
