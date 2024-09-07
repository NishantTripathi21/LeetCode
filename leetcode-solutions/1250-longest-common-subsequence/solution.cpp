class Solution {
public:
    //inclusion exclusion principle
    int usingRecursion(string &text1,string &text2,int i,int j){
        if(i>=text1.size())return 0;
        if(j>=text2.size())return 0;
        int ans=0;
        if(text1[i]==text2[j]){
            ans=1 + usingRecursion(text1,text2,i+1,j+1);
        }
        else{
            ans=0 + max(usingRecursion(text1,text2,i,j+1),usingRecursion(text1,text2,i+1,j));
        }
        return ans;
    }
    int usingMemoisation(string &text1,string &text2,int i,int j,vector<vector<int>>&dp){
        if(i>=text1.size())return 0;
        if(j>=text2.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans=0;
        if(text1[i]==text2[j]){
            ans=1 + usingMemoisation(text1,text2,i+1,j+1,dp);
        }
        else{
            ans=0 + max(usingMemoisation(text1,text2,i,j+1,dp),usingMemoisation(text1,text2,i+1,j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int usingTabulaton(string &text1,string &text2){
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        for(int row=0;row<=text1.size();row++){
            dp[row][text2.size()]=0;
        }
        for(int col=0;col<=text2.size();col++){
            dp[text1.size()][col]=0;
        }

        for(int row=text1.size()-1;row>=0;row--){
            for(int col=text2.size()-1;col>=0;col--){
                int ans=0;
                if(text1[row]==text2[col]){
                    ans=1 + dp[row+1][col+1];
                }
                else{
                    ans=0 + max(dp[row][col+1],dp[row+1][col]);
                }
                dp[row][col]=ans;
            }
        }
        return dp[0][0];

    }
    int usingTabulationSpaceOptimisation(string &text1,string &text2){
        vector<int>prev(max(text1.size()+2,text2.size()+2),0);
        vector<int>curr(max(text1.size()+2,text2.size()+2),0);
        for(int col=text2.size()-1;col>=0;col--){
            for(int row=text1.size()-1;row>=0;row--){
                int ans=0;
                if(text1[row]==text2[col]){
                    ans=1+prev[row+1];
                }
                else{
                    ans=0 + max(prev[row],curr[row+1]);
                }
                curr[row]=ans;
            }
            prev=curr;

        }
        return curr[0];

    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return usingTabulationSpaceOptimisation(text1,text2);
    }
};
