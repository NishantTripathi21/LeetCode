class Solution {
public:
    int usingRec(string word1, string word2,int i,int j,vector<vector<int>>&dp){
        if(i == word1.size()){
            return word2.size() - j;
        }
        if(j== word2.size()){
            return word1.size() - i;
        }
        if(dp[i][j] != -1)return dp[i][j];
        int ans=0;
        if(word1[i]==word2[j]){
            ans=0 + usingRec(word1,word2,i+1,j+1,dp);
        }
        else{
            ans= 1+ min(usingRec(word1,word2,i+1,j,dp),usingRec(word1,word2,i,j+1,dp));
        }
        return dp[i][j]= ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return usingRec(word1,word2,0,0,dp);
    }
};
