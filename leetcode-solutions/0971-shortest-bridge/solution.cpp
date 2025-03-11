class Solution {
public:
    int n,m;
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& grid, int row, int col, queue<pair<int,int>>& q) {
        grid[row][col]= -1;
        q.push({row,col});
        for(auto [dx,dy]: directions) {
            int nr = row + dx;
            int nc = col + dy;
            if(nr < n && nr >= 0 && nc < m && nc >= 0 && grid[nr][nc] == 1) {
                dfs(grid,nr,nc,q);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int,int>>q;
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found = true; 
                }
            }
        }
        int flips = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [row,col] = q.front();
                q.pop();
                if(grid[row][col] == 1)return flips;
                grid[row][col] = -1;
                for(auto [dx,dy]: directions) {
                    int nr = row + dx;
                    int nc = col + dy;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        if (grid[nr][nc] == 1) return flips;
                        if (grid[nr][nc] == 0) {
                            grid[nr][nc] = -1;
                            q.push({nr, nc});
                        }
                    }
                }
            }
            flips++;
        }
        return flips;
    }
};
