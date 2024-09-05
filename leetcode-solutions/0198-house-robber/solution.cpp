class Solution {
public:
    int robHouseRE(vector<int>& nums,int i,vector<int>&dp){
        if(i>nums.size()-1 ) return 0;
        if(dp[i] != -1){
            return dp[i];
        }
        // one case
        int rob1= nums[i]+robHouseRE(nums,i+2,dp);
        int rob2=0+ robHouseRE(nums,i+1,dp);
        dp[i]=max(rob1,rob2);
        return max(rob1,rob2);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return robHouseRE(nums,0,dp);
        
    }
};
