class Solution {
public:
    int usingRec(vector<int>& prices,int k ,int index, int buy,vector<vector<vector<int>>>&dp){
        if(index==prices.size()){
            return 0;
        }
        if(k==0){
            return 0;
        }
        if(dp[k][index][buy] != -1)return dp[k][index][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[index]+ usingRec(prices,k,index+1,0,dp), 0+ usingRec(prices,k,index+1,1,dp));
        }
        else{
            profit=max(prices[index] + usingRec(prices,k-1,index+1,1,dp) , usingRec(prices,k,index+1,0,dp));
        }
        return dp[k][index][buy]=profit;
    }
    int usingTabulation(vector<int>&prices,int K){
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(K+1,vector<int>(2,0)));
        for(int index=prices.size()-1;index>=0;index--){
            for(int k=1;k<=K;k++){
                for(int buy=0;buy<=1;buy++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[index]+ dp[index+1][k][0], 0+ dp[index+1][k][1]);
                    }
                    else{
                        profit=max(prices[index] + dp[index+1][k-1][1] , dp[index+1][k][0]);
                    }
                    dp[index][k][buy]=profit;
                }
            }
        }
        return dp[0][K][1];
    }
    int usingSpaceOptimisation(vector<int>& prices,int K){
        vector<vector<int>>after(K+1,vector<int>(2,0));
        vector<vector<int>>curr(K+1,vector<int>(2,0));
        for(int index=prices.size()-1;index>=0;index--){
            for(int k=1;k<=K;k++){
                for(int buy=0;buy<=1;buy++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[index]+ after[k][0], 0+ after[k][1]);
                    }
                    else{
                        profit=max(prices[index] + after[k-1][1] , after[k][0]);
                    }
                    curr[k][buy]=profit;
                }
            }
            after=curr;
        }
        return after[K][1];
    }
    int maxProfit(int k, vector<int>& prices) {
        // vector<vector<vector<int>>>dp(k +2,vector<vector<int>>(prices.size()+1,vector<int>(2,-1)));
        // return usingRec(prices,k,0,1,dp);
        return usingSpaceOptimisation(prices,k);
    }
};
