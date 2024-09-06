class Solution {
public:
    int solveUsingRecursionDp(vector<int>&coins,int n,vector<int>&dp){
        //memoisation technique
        if(n ==0) return 0;
        if(n < 0)return INT_MAX;
        if(dp[n] != -1)return dp[n];
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(n - coins[i] >= 0 ){
                int ans = solveUsingRecursionDp(coins,n-coins[i],dp);
                if(ans != INT_MAX){
                    mini=min(mini,ans+1);
                }
            }
        }
        dp[n]=mini;
        return dp[n];
    }
    int solveUsingTabulation(vector<int>&coins,int n){
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int value=1;value<=n;value++){
            int mini=INT_MAX;
            for(int i=0;i<coins.size();i++){
                if(value - coins[i] >= 0 ){
                    int ans = dp[value-coins[i]];
                    if(ans != INT_MAX){
                        mini=min(mini,ans+1);
                    }
                }
            }
            dp[value]=mini;
        }
        return dp[n];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
       int ans=solveUsingTabulation(coins,amount);
       return ans==INT_MAX?-1: ans;
    }
};
