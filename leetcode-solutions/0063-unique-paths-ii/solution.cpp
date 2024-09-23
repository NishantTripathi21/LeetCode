class Solution {
public:
    bool isSafe(vector<vector<int>>& obstacleGrid,int x,int y){
        if( x>=0 && x<=obstacleGrid.size()-1 && y>=0 && y<=obstacleGrid[0].size()-1 && obstacleGrid[x][y] != 1){
            return true;
        }
        return false;
    }
    int usingRec(vector<vector<int>>& obstacleGrid,int x,int y,vector<vector<int>>&dp){
        if(obstacleGrid[x][y] == 1)return 0;
        if(x==obstacleGrid.size()-1 && y==obstacleGrid[0].size()-1 && obstacleGrid[x][y] != 1){
            return 1;
        }
        if(dp[x][y] != -1)return dp[x][y];
        int down=0;
        if(isSafe(obstacleGrid,x+1,y)){
            down=usingRec(obstacleGrid,x+1,y,dp);
        }
        int right=0;
        if(isSafe(obstacleGrid,x,y+1)){
            right=usingRec(obstacleGrid,x,y+1,dp);
        }
        return dp[x][y]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //if(obstacleGrid[0][0] == 1)return 0;
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return usingRec(obstacleGrid,0,0,dp);
    }
};
