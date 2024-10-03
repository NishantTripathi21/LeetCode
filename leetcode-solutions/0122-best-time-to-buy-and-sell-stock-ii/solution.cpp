class Solution {
public:
    //another mthod by using include exclude
    int usingRec2(vector<int>&prices,int index,int buy,vector<vector<int>>&dp){
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit=0;
        if(buy){
            //when you can buy. you try buy on the index day or skip the index day
            profit=max(-prices[index] + usingRec2(prices,index+1,0,dp),0+ usingRec2(prices,index+1,1,dp));
        }
        else{
            //if u have already bought,you sell on index day, or you may skip and sell other day
            profit=max( prices[index] + usingRec2(prices,index+1,1,dp) , 0+ usingRec2(prices,index+1,0,dp));
        }
        return dp[index][buy]=profit;
    }

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
    //no spaceOptmisation is possible
    int maxProfit(vector<int>& prices) {
        //vector<int>dp(prices.size()+1,-1);
        //return usingRec(prices,0,dp);
        vector<vector<int>>dp(prices.size()+1,vector<int>(3,-1));
        return usingRec2(prices,0,1,dp);
    }
};
