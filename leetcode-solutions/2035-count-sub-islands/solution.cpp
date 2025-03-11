class Solution {
public:
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col,bool& subIsland) {
        int n = grid1.size();
        int m = grid1[0].size();
        if(grid2[row][col] != grid1[row][col]) subIsland = false;
        grid2[row][col] = 0;
        for(auto [dx,dy]: directions) {
            int nr = row + dx;
            int nc = col + dy;
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid2[nr][nc] == 1) {
                dfs(grid1,grid2,nr,nc,subIsland);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int ans = 0;
        for(int i= 0; i< n; i++) {
            for(int j= 0; j< m; j++) {
                if(grid2[i][j] == 1) {
                    bool isIsland = true;
                    dfs(grid1,grid2,i,j,isIsland);
                    if(isIsland){
                        ans++;
                        //cout<<" i: "<<i<<" j: "<<j<<" ans: "<<ans<<endl;
                    }
                }
            }
        }
        return ans;
    }
};
