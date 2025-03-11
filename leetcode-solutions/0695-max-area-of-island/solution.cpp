class Solution {
public:
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    void bfs(vector<vector<int>>& grid, int row, int col,int& ans) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q; //{row,col}
        q.push({row,col});
        grid[row][col] = 0;
        int area = 0;
        while(!q.empty()) {
            auto [r,c] = q.front();
            area++;
            //cout<<" r: "<<r<<" c: "<<c<<" ans: "<<area<<endl;
            q.pop();
            for(auto [dx,dy]: directions) {
                int nr = r + dx;
                int nc = c + dy;
                //cout<<" nr: "<<nr<<" nc: "<<nc<<endl;
                if(nr < n && nr >= 0 && nc < m && nc >= 0 && grid[nr][nc] == 1) {
                    grid[nr][nc] = 0;
                    q.push({nr,nc});
                }
            }
        }
        ans = max(ans,area);
        //cout<<" finish "<<endl;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i= 0; i< n; i++) {
            for(int j= 0; j< m; j++) {
                if(grid[i][j] == 1) {
                    bfs(grid,i,j,ans);
                }
            }
        }
        return ans;
    }
};
