class Solution {
public:
    int usingRecursion(int start,int end){
        if(start >= end)return 0;
        int ans=INT_MAX;
        for(int i=start;i<=end;i++){
            ans=min(ans, i+ max(usingRecursion(start,i-1),usingRecursion(i+1,end)));
        }
        return ans;
    }
    int usingMemoisation(int start,int end,vector<vector<int>>&dp){
        if(start >= end)return 0;
        if(dp[start][end] != -1)return dp[start][end];
        int ans=INT_MAX;
        for(int i=start;i<=end;i++){
            ans=min(ans, i+ max(usingMemoisation(start,i-1,dp),usingMemoisation(i+1,end,dp)));
        }
        dp[start][end]=ans;
        return ans;
    } 
    int usingTabulation(int n){
        vector<vector<int>>dp(n+2,vector<int>(n+1,0));
        for(int start=n-1; start>=1;start--){
            for(int end=start+1;end<=n;end++){
                int ans=INT_MAX;
                for(int i=start;i<=end;i++){
                    ans=min(ans, i+ max(dp[start][i-1],dp[i+1][end]));
                }
                dp[start][end]=ans;
            }
        }
        return dp[1][n];
    }   
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return usingTabulation(n);
    }
};
