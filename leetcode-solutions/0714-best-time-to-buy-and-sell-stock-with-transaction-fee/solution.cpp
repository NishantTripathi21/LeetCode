class Solution {
public:
    int usingRec(vector<int>& prices, int &fee, int index ,int buy,vector<vector<int>>&dp){
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit=0;
        if(buy){
            profit=max(-prices[index] + usingRec(prices,fee,index+1,0,dp), usingRec(prices,fee,index+1,1,dp));
        }
        else{
            profit=max(prices[index] -fee + usingRec(prices,fee,index+1,1,dp), usingRec(prices,fee,index+1,0,dp));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,-1));
        return usingRec(prices,fee,0,1,dp);
    }
};
