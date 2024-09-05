class Solution {
public:
    int houseRobber_helper(vector<int>& nums,int start,int end,vector<int>&dp){
        if(start>end ) return 0;
        // one case
        if(dp[start] != -1)return dp[start];
        int rob1= nums[start]+houseRobber_helper(nums,start+2,end,dp);
        int rob2=0+ houseRobber_helper(nums,start+1,end,dp);
        dp[start]=max(rob1,rob2);
        return dp[start];

    }
    int rob(vector<int>& nums) {
        //first method
        vector<int>dp(nums.size(),-1);
        if(nums.size()>1){
        int option1=houseRobber_helper(nums,0,nums.size()-2,dp);
        vector<int>dp2(nums.size(),-1);
        int option2=houseRobber_helper(nums,1,nums.size()-1,dp2);
        return max(option1,option2);
        }
        else{
            return nums[0];
        }
        
    }
};
