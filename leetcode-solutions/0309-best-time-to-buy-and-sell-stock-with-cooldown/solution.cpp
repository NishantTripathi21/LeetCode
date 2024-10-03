class Solution {
public:
    int usingRec(vector<int>& prices, int index ,int buy,vector<vector<int>>&dp){
        if(index >= prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1)return dp[index][buy];
        int profit=0;
        if(buy){
            profit= max(-prices[index] + usingRec(prices,index+1,0,dp), usingRec(prices, index+1, 1,dp));
        }
        else{
            profit=max(prices[index] + usingRec(prices,index+2,1,dp) , usingRec(prices,index+1,0,dp));
        }
        return dp[index][buy]=profit;
    }
    int usingTabulation(vector<int>& prices){
        vector<vector<int>>dp(prices.size()+3,vector<int>(2,0));
        for(int index=prices.size()-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit= max(-prices[index] + dp[index+1][0],dp[index+1][1]);
                }
                else{
                    profit=max(prices[index] + dp[index+2][1] , dp[index+1][0]);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
    int usingSpaceOptimisation(vector<int>& prices){
        vector<int>after(2,0);
        vector<int>after2(2,0);
        vector<int>curr(2,0);
        for(int index=prices.size()-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit= max(-prices[index] + after[0],after[1]);
                }
                else{
                    profit=max(prices[index] + after2[1] , after[0]);
                }
                curr[buy]=profit;
            }
            after2=after;
            after=curr;
        }
        return after[1];
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        // return usingRec(prices,0,1,dp);
        return usingSpaceOptimisation(prices);
    }
};
