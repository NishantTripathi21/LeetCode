class Solution {
public:
    int usingRec(vector<int>& nums, int index, int parity, int prev,vector<vector<vector<int>>>&dp) {
        if(index >= nums.size()) return 0;
        if(dp[index][parity+1][prev] != -1)return dp[index][parity+1][prev];
        int recAns = 0;
        if(parity != -1) {
            if(parity == 0) {// even
                if(!((nums[index] + prev ) & 1)) {
                    recAns = 1 + usingRec(nums,index+1,parity,nums[index]%2,dp);
                }
                else {
                    recAns = usingRec(nums,index+1,parity,prev,dp);
                }
            }
            else{
                if(( nums[index] + prev ) & 1 ) {
                    recAns = 1 + usingRec(nums,index+1,parity,nums[index]%2,dp);
                }
                else {
                    recAns = usingRec(nums,index+1,parity,prev,dp);
                }
            }
        }
        else {
            recAns = max(usingRec(nums,index+1,parity,prev,dp),max(1 + usingRec(nums,index+1,0,nums[index]%2,dp),1+ usingRec(nums,index+1,1,nums[index]%2,dp)));
        }
        return dp[index][parity+1][prev] = recAns;
    }

    int maximumLength(vector<int>& nums) {
        vector<vector<vector<int>>>dp(nums.size()+1,vector<vector<int>>(3,vector<int>(3,-1)));
        return usingRec(nums,0,-1,0,dp);
    }
};
