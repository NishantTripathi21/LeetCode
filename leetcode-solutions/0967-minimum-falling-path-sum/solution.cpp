class Solution {
public:
    int usingRec(vector<vector<int>>& matrix,int x,int y,vector<vector<int>>&dp){
        if(x==matrix.size()-1){
            return matrix[x][y];
        }
        if(dp[x][y] != -1)return dp[x][y];
        int preDia=INT_MAX;
        if( y-1 >=0){
            preDia=matrix[x][y] + usingRec(matrix,x+1,y-1,dp);
        }
        int rightBelow=matrix[x][y] + usingRec(matrix,x+1,y,dp);
        int nextDia=INT_MAX;
        if(y+1 <= matrix[0].size()-1){
            nextDia=matrix[x][y] + usingRec(matrix,x+1,y+1,dp);
        }
        return dp[x][y]=min(preDia,min(nextDia,rightBelow));
    }
    int usingTabulation(vector<vector<int>>& matrix){
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int col=0;col<matrix[0].size();col++){
            dp[matrix.size()-1][col]=matrix[matrix.size()-1][col];
        }
        for(int x=matrix.size()-2;x>=0;x--){
            for(int y=matrix[0].size()-1;y>=0;y--){
                int preDia=INT_MAX;
                if( y-1 >=0){
                    preDia=matrix[x][y] + dp[x+1][y-1];
                }
                int rightBelow=matrix[x][y] + dp[x+1][y];
                int nextDia=INT_MAX;
                if(y+1 <= matrix[0].size()-1){
                    nextDia=matrix[x][y] + dp[x+1][y+1];
                }
                dp[x][y]=min(preDia,min(nextDia,rightBelow));
            }
        }
        int ans = INT_MAX;
        for (int col = 0; col < matrix[0].size(); col++) {
            ans = min(ans, dp[0][col]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        // for(int i=0;i<matrix[0].size();i++){
        //     //vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        //     int temp=usingTabulation(matrix,i);
        //     ans=min(ans,temp);
        // }
        return usingTabulation(matrix);
    }
};
