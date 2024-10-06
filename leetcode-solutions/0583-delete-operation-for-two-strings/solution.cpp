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
    //using LCS
    //keep LCS intact , and delete other elements from both strings, this will be minimun opertions
    //LCS code of space optmisation
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
    int minDistance(string word1, string word2) {
        // vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        // return usingRec(word1,word2,0,0,dp);
        int LCS=usingTabulationSpaceOptimisation(word1,word2);
        return word1.size()-LCS +  word2.size()-LCS;
    }
};
