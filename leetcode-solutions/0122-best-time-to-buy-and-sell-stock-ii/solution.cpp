class Solution {
public:
    int usingRec(vector<int>&prices,int buyDay,vector<int>&dp){
        if(buyDay==prices.size()-1){
            return 0;
        }
        if(dp[buyDay] != -1)return dp[buyDay];
        int maxi=0;
        for(int i=buyDay;i<prices.size();i++){
            maxi=max(maxi,prices[i]-prices[buyDay] + usingRec(prices,i+1,dp));
        }
        return dp[buyDay]=maxi;
    }
    int usingTabulation(vector<int>&prices){
        vector<int>dp(prices.size()+1,0);
        //base case is handled
        for(int buyDay=prices.size()-1;buyDay>=0;buyDay--){
            int maxi=0;
            for(int i=buyDay;i<prices.size();i++){
                maxi=max(maxi,prices[i]-prices[buyDay] + dp[i+1]);
            }
            dp[buyDay]=maxi;
        }
        return dp[0];
    }
    int maxProfit(vector<int>& prices) {
        //vector<int>dp(prices.size()+1,-1);
        //return usingRec(prices,0,dp);
        return usingTabulation(prices);
    }
};
