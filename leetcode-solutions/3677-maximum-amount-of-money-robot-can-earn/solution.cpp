class Solution {
public:
    int rec( vector<vector<int>>& coins, int row, int col,int neutralised,vector<vector<vector<int>>>&dp){
        if( row >= coins.size() || col >= coins[0].size()){
            return INT_MIN;
        }
        if( dp[row][col][neutralised] != INT_MIN){
            return dp[row][col][neutralised];
        }
        int collected1 = 0;
        int collected2 = 0;
        
        if( coins[row][col] >=0){
            collected1 = coins[row][col];
            int recAns  = max( rec(coins,row+1,col,neutralised,dp), rec(coins,row,col+1,neutralised,dp));
            if( recAns > INT_MIN){
                collected1 += recAns;
            }
            return dp[row][col][neutralised] = collected1;
        }
        else {
            // if we can neutralise
            if( neutralised < 2){
                //neutralised 
                int anubhav = 0;
                int recAns = max( rec(coins,row+1,col,neutralised+1,dp), rec(coins,row,col+1,neutralised+1,dp));
                if( recAns > INT_MIN){
                    anubhav += recAns;
                }

                // dont neutralise it
                int virat = coins[row][col];
                int recAns2 = max(rec(coins,row+1,col,neutralised,dp), rec(coins,row,col+1,neutralised,dp));
                if( recAns2 > INT_MIN){
                    virat += recAns2;
                }
                return dp[row][col][neutralised]=max(virat,anubhav);
            }
            else{
                collected2 = coins[row][col];
                int recAns = max(rec(coins,row+1,col,neutralised,dp), rec(coins,row,col+1,neutralised,dp));
                if( recAns > INT_MIN){
                    collected2 += recAns;
                }
                return dp[row][col][neutralised]=collected2;
            }
        }
    }
    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<vector<int>>>dp(coins.size()+1,vector<vector<int>>(coins[0].size()+1,vector<int>(3,INT_MIN)));
        return rec( coins, 0 , 0, 0,dp);
    }
};
