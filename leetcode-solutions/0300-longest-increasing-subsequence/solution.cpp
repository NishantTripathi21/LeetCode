class Solution {
public:
    int usingRecursion(vector<int>& nums,int prev,int curr,vector<vector<int>>&dp){
        if(curr >= nums.size())return 0;
        //shifting of index of previous because previous has been initialised with -1
        if(dp[curr][prev+1] != -1)return dp[curr][prev+1];
        int include=0;
        if(prev==-1 || nums[curr] > nums[prev]){
            include=1+ usingRecursion(nums,curr,curr+1,dp);
        }
        int exclude=0  + usingRecursion(nums,prev,curr+1,dp);
        int ans=max(exclude,include);
        dp[curr][prev+1]=ans;
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr=0;
        int prev=-1;
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+2 , -1));
        int ans=usingRecursion(nums,prev,curr,dp);
        return ans;
    }
};
