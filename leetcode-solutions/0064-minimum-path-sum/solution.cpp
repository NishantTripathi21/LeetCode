class Solution {
public:
    int usingRec(vector<vector<int>>& grid,int x,int y,vector<vector<int>>&dp){
        if(x==grid.size()-1 && y==grid[0].size()-1){
            return grid[x][y];
        }
        if(dp[x][y] != -1)return dp[x][y];
        int down=INT_MAX;
        if(x+1 <= grid.size()-1){
            down=grid[x][y] + usingRec(grid,x+1,y,dp);
        }
        int right=INT_MAX;
        if(y+1 <= grid[0].size()-1){
            right = grid[x][y] + usingRec(grid,x,y+1,dp);
        }
        return dp[x][y]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return usingRec(grid,0,0,dp);
    }
};
