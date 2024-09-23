class Solution {
public:
    int usingRec(int M,int N, int x,int y,vector<vector<int>>&dp){
        if(x>=M-1 && y>=N-1){
            return 1;
        }
        if(dp[x][y] != -1)return dp[x][y];
        //right
        int right=0;
        if(y+1<=N-1){
            right=(usingRec(M,N,x,y+1,dp));
        }
        int down=0;
        if(x+1 <= M-1){
            down=(usingRec(M,N,x+1,y,dp));
        }
        dp[x][y]= (down+right);
        return dp[x][y];
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return usingRec(m,n,0,0,dp);
    }
};
