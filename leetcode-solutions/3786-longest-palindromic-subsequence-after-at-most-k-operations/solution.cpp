class Solution {
public:
    int minOps(char c1, char c2) {
        int diff = abs(c1 - c2);
        return min(diff, 26 - diff);
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.length();
        
        // Create 3D DP array
        vector<vector<vector<int>>> dp(
            n, 
            vector<vector<int>>(
                n, 
                vector<int>(k + 1, 0)
            )
        );
        
        // Initialize base cases for single characters
        for(int i = 0; i < n; i++) {
            for(int ops = 0; ops <= k; ops++) {
                dp[i][i][ops] = 1;
            }
        }
        
        // Fill the dp table
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                for(int ops = 0; ops <= k; ops++) {
                    // Case 1: Don't include either character
                    dp[i][j][ops] = max(dp[i+1][j][ops], dp[i][j-1][ops]);
                    
                    // Case 2: If we have enough operations to make characters equal
                    int required = minOps(s[i], s[j]);
                    if(ops >= required) {
                        int remainingOps = ops - required;
                        // Include both characters
                        if(i + 1 <= j - 1) {
                            dp[i][j][ops] = max(dp[i][j][ops], 
                                              dp[i+1][j-1][remainingOps] + 2);
                        } else {
                            dp[i][j][ops] = max(dp[i][j][ops], 2);
                        }
                    }
                }
            }
        }
        
        return dp[0][n-1][k];
    }
};
