class Solution {
public:
    // int usingRec2(vector<int>& prices,int index,int trx,vector<vector<int>>&dp){
    //     if(trx==2){
    //         return 0;
    //     }
    //     if(index>=prices.size()){
    //         return 0;
    //     }
    //     if(dp[index][trx] != -1)return dp[index][trx];
    //     int maxi=0;
    //     for(int i=index+1;i<prices.size();i++){
    //         int currProfit=prices[i]-prices[index];
    //         int nextBuy=0;
    //         for(int j=i+1;j<prices.size();j++){
    //             nextBuy=max(usingRec2(prices,j,trx+1,dp),nextBuy);
    //         }
    //         maxi=max(currProfit+nextBuy,maxi);
    //     }
    //     return dp[index][trx]=maxi;
    // }
    
    // int usingRec(vector<int>& prices,int index,int trx){
    //     if(trx==2){
    //         return 0;
    //     }
    //     if(index>=prices.size()){
    //         return 0;
    //     }
    //     int maxi=0;
    //     for(int i=index+1;i<prices.size();i++){
    //         for(int j=i+1;j<prices.size();j++){
    //             maxi=max(prices[i]-prices[index] + usingRec(prices,j,trx+1),maxi);
    //         }
    //         cout<<maxi<<endl;
    //     }
    //     return maxi;
    // }
    int usingRec(vector<int>& prices,int index,int buy,int trx,vector<vector<vector<int>>>&dp){
        if(trx==2)return 0;
        if(index==prices.size())return 0;
        if(dp[index][buy][trx] != -1)return dp[index][buy][trx];
        int profit=0;
        if(buy){
            profit=max(-prices[index] + usingRec(prices,index+1,0,trx,dp), usingRec(prices,index+1,1,trx,dp));
        }
        else{
            //transaction completed only after selling bought stocks
            profit=max(prices[index] + usingRec(prices,index+1,1,trx+1,dp), usingRec(prices,index+1,0,trx,dp));
        }
        return dp[index][buy][trx]=profit;
    }
    int usingTabulation(vector<int>&prices){
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(6,0)));
        for(int index=prices.size()-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int trx=1;trx>=0;trx--){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[index] + dp[index+1][0][trx], dp[index+1][1][trx]);
                    }
                    else{
                        profit=max(prices[index] + dp[index+1][1][trx+1], dp[index+1][0][trx]);
                    }
                    dp[index][buy][trx]=profit;
                }
            }
        }
        return dp[0][1][0];
    }
    int usingSpaceOptimisation(vector<int>& prices){
        vector<vector<int>>after(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        for(int index=prices.size()-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int trx=1;trx>=0;trx--){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[index] + after[0][trx], after[1][trx]);
                    }
                    else{
                        profit=max(prices[index] + after[1][trx+1], after[0][trx]);
                    }
                    curr[buy][trx]=profit;
                }
            }
            after=curr;
        }
        return after[1][0];
    }
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        // for(int i=0;i<prices.size()-1;i++){
        //     vector<vector<int>>dp(prices.size(),vector<int>(3,-1));
        //     maxi=max(maxi,usingRec2(prices,i,0,dp));
        // }
        // return maxi;
        //vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(5,-1)));
        return usingSpaceOptimisation(prices);
    }
};
