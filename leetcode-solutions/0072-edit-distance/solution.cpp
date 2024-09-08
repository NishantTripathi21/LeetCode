class Solution {
public:
    //all possible ways, kind of inclusion exclusion
    int usingRecursion(string &word1,string &word2, int i, int j){
        if(i>=word1.size()){
            return word2.size() - j;
        }
        if(j>=word2.size()){
            return word1.size() - i;
        }
        int ans=0;
        if(word1[i]==word2[j]){
            ans= 0+ usingRecursion(word1,word2,i+1,j+1);
        }
        else{
            int replace= 1+ usingRecursion(word1,word2,i+1,j+1);
            int deletion=1 + usingRecursion(word1,word2, i+1,j);
            int insertion= 1+ usingRecursion(word1,word2,i,j+1);
            ans=min(insertion,min(deletion,replace));
        }
        return ans;
    }
    int usingMemoisation(string &word1,string &word2, int i, int j,vector<vector<int>>&dp){
        if(i==word1.size()){
            return word2.size() - j;
        }
        if(j==word2.size()){
            return word1.size() - i;
        }
        if(dp[i][j] != -1)return dp[i][j];
        int ans=0;
        if(word1[i]==word2[j]){
            ans= 0+ usingMemoisation(word1,word2,i+1,j+1,dp);
        }
        else{
            int replace= 1+ usingMemoisation(word1,word2,i+1,j+1,dp);
            int deletion=1 + usingMemoisation(word1,word2, i+1,j,dp);
            int insertion= 1+ usingMemoisation(word1,word2,i,j+1,dp);
            ans=min(insertion,min(deletion,replace));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int usingTabulation(string &word1,string &word2){
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int col =0;col <=word2.size();col++){
            dp[word1.size()][col]=word2.size()-col;    
        }
        for(int row=0;row<=word1.size();row++){
            dp[row][word2.size()]=word1.size()-row;
        }
        for(int row=word1.size()-1;row>=0;row--){
            for(int col=word2.size()-1;col>=0;col--){
                int ans=0;
                if(word1[row]==word2[col]){
                    ans= 0+ dp[row+1][col+1];
                }
                else{
                    int replace= 1+ dp[row+1][col+1];
                    int deletion=1 + dp[row+1][col];
                    int insertion= 1+ dp[row][col+1];
                    ans=min(insertion,min(deletion,replace));
                }
                dp[row][col]=ans;
            }
        }
        return dp[0][0];
    }
    //space optimisation
    int usingTabulationSpaceOptimisation(string &word1,string &word2){
    //vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
    vector<int>curr(word1.size()+1,0);
    vector<int>prev(word1.size()+1,0);
    for(int i=0;i<=word1.size();i++){
        prev[i]=word1.size()-i;
    }

    curr[word1.size()]=word2.size()-word2.size()-1;

    for(int col=word2.size()-1;col>=0;col--){

        curr[word1.size()]=word2.size()-col;

        for(int row=word1.size()-1;row>=0;row--){

            int ans=0;
            if(word1[row]==word2[col]){
                ans= 0 + prev[row+1];
            }
            else{
                int replace= 1+ prev[row+1];
                int deletion=1 + curr[row+1];
                int insertion= 1+ prev[row];
                ans=min(insertion,min(deletion,replace));
            }
            curr[row]=ans;
        }
        prev=curr;
    }
    return prev[0];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return usingTabulationSpaceOptimisation(word1,word2);
    }
};
