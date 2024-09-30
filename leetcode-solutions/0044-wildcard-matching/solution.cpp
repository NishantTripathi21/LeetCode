class Solution {
public:
    bool usingRec(string& s, string& p,int i,int j,vector<vector<int>>&dp){
        if(i >= s.size() && j>= p.size()){
            return true;
        }
        if(i>= s.size() && j <= p.size() ){
            for(int n=j;n<p.size();n++){
                if(p[n] != '*')return false;
            }
            return true;
        }
        if( i <= s.size() && j>=p.size()){
            return false;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i]==p[j] || p[j] == '?'){
            return dp[i][j]= usingRec(s,p,i+1,j+1,dp);
        }
        if(p[j] =='*'){
            return dp[i][j]=usingRec(s,p,i+1,j,dp) || usingRec(s,p,i,j+1,dp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        return usingRec(s,p,0,0,dp);
    }
};
