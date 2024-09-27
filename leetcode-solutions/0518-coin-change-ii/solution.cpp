class Solution {
public:
    int usingRec(int amount, vector<int>& coins,int index,vector<vector<int>>&dp){
        //2D dp method
        if(amount < 0)return 0;
        if(index >= coins.size() && amount != 0){
            return 0;
        }
        if(amount ==0){
            return 1;
        }
        if(dp[amount][index] != -1)return dp[amount][index];
        int exclude=usingRec(amount,coins,index+1,dp);
        int include=usingRec(amount-coins[index],coins,index,dp);
        return dp[amount][index]=include+exclude;
    }
    long long usingTabulation(vector<int>&coins,int amount){
        vector<vector<long>>dp(amount+10,vector<long>(coins.size()+10,0));
        for(int col=0;col<=coins.size();col++){
            dp[0][col]=1;
        }
        for(int row=0;row<=amount;row++){
            for(int col=coins.size()-1;col>=0;col--){
                long exclude=dp[row][col+1];
                long include=0;
                if(row-coins[col] >= 0) include=dp[row-coins[col]][col];
                dp[row][col]=include+exclude >= INT_MAX? INT_MAX:include+exclude;
                // if (dp[row][col] > INT_MAX) {
                // dp[row][col] = INT_MAX;  // You could cap it if necessary
                // }
            }
        }
        return dp[amount][0];

    }
    int change(int amount, vector<int>& coins) {
        //vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1,-1));
        return usingTabulation(coins,amount);
    }
};
