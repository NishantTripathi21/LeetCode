class Solution {
public:
    int usingRec(vector<vector<int>>& triangle,int x,int y,vector<vector<int>>&dp){
        if(x==triangle.size()-1){
            return triangle[x][y];
        }
        if(dp[x][y] != -1)return dp[x][y];
        int firstMove=INT_MAX;
        if( true){
            firstMove=triangle[x][y]+ usingRec(triangle,x+1,y,dp);
        }
        int secondMove=INT_MAX;
        if( true){
            secondMove=triangle[x][y]+usingRec(triangle,x+1,y+1,dp);
        }
        return dp[x][y]=min(firstMove,secondMove);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        return usingRec(triangle,0,0,dp);
    }
};
