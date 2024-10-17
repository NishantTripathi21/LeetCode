class Solution {
public:
    bool usingRec(string& s, string& p,int i,int j,vector<vector<int>>&dp){
        if(i>=s.size() && j>=p.size()){
            return true;
        }
        if( i>= s.size() && j <= p.size() ){
            //if s string ends but p string has charector left to match
            for(int n=j;n<p.size();n++){
                if(p[n] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i]==p[j] || p[j] == '?'){
            // if one charecter matches 
            return dp[i][j]=usingRec(s,p,i+1,j+1,dp);
        }
        if(p[j]=='*'){
            //if charector of t is star, it can match with any number of elements including zero
            //i+1,j means star is matched with one charecter of s and called for furthur star matching,
            //i,j+1 means star matched with no element in s 
            return dp[i][j] = usingRec(s,p,i+1,j,dp) || usingRec(s,p,i,j+1,dp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size() +1 ,vector<int>(p.size() +1 ,-1));
        return usingRec(s,p,0,0,dp);
    }
};
