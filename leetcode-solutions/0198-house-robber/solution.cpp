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

    int usingTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,0);
        dp[n] = 0;
        for(int i= n-1; i>= 0; i--) {
            int incl = 0;
            if(i+2 < n) {
                incl = nums[i] + dp[i+2];
            }
            else {  
                incl = nums[i];
            }
            int exc = 0 + dp[i+1];
            dp[i]= max(incl,exc);
        }
        return dp[0];
    }

    int usingSO(vector<int>& nums) {
        // dp[i+2] = second;
        //dp[i+1] = first;
        int n = nums.size();
        int first = 0,second = 0;
        int ans = 0;
        for(int i= n-1; i>= 0; i--) {
            int incl = 0;
            if(i+2 < n) {
                incl = nums[i] + second;
            }
            else {  
                incl = nums[i];
            }
            int exc = 0 + first;
            ans= max(incl,exc);
            second = first;
            first = ans;
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        // int n=nums.size();
        // vector<int>dp(n,-1);
        // return robHouseRE(nums,0,dp);
        return usingTabulation(nums);
        
    }
};
