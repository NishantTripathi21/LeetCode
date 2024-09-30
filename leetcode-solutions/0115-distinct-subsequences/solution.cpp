class Solution {
public: 
    int usingRec(string s, string t, int i ,int j,vector<vector<int>>&dp){
        if(j >= t.size()){
            return 1;
        }
        if(i>=s.size()){
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]= usingRec(s,t,i+1,j+1,dp) + usingRec(s,t,i+1,j,dp);
        }
        else{
            return dp[i][j]=usingRec(s,t,i+1,j,dp);
        }
    }

    long usingTabulation(string s, string t){
        vector<vector<long>>dp(s.size()+1,vector<long>(t.size()+1,0));
        //base case where return is 0, is handled ans we need to handle where return is 1;
        for(int row=0;row<=s.size();row++){
            dp[row][t.size()]=1;
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j]= dp[i+1][j+1] + dp[i+1][j];
                }
                else{
                    dp[i][j]=dp[i+1][j];
                }
                if(dp[i][j] >INT_MAX){
                    dp[i][j]=INT_MAX;
                }
            }
        }
        return dp[0][0];
    }
    int numDistinct(string s, string t) {
        //vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        //return usingRec(s,t,0,0,dp);
        return usingTabulation(s,t);

    }
};
