class Solution {
public:
    bool usingRecursion(vector<int>&nums,int sum,int target,int index){
        if(index >= nums.size())return false;
        if(target==sum)return true;
        if(target < sum)return false;
        bool include=usingRecursion(nums,sum+nums[index],target,index+1);
        bool exclude=usingRecursion(nums,sum,target,index+1);
        return include || exclude;
    }
    bool usingMemoisation(vector<int>&nums,int sum,int &target,int index,vector<vector<int>>&dp){
        if(index >= nums.size())return 0;
        if(target==sum)return 1;
        if(target < sum)return 0;
        if(dp[sum][index] != -1)return dp[sum][index];
        bool include=usingMemoisation(nums,sum+nums[index],target,index+1,dp);
        bool exclude=usingMemoisation(nums,sum,target,index+1,dp);
        dp[sum][index] = include || exclude;
        return dp[sum][index];
    }

    bool usingTabulation(vector<int>&nums,int sum,int &target){
        vector<vector<int>>dp(target+1,vector<int>(nums.size()+2,0));
        for(int col=0;col<=nums.size();col++){
            dp[target][col]=1;
        }
        for(int sum=target;sum>=0;sum--){
            for(int index=nums.size()-1;index >=0;index--){
                bool include=0;
                if(sum + nums[index] <=target){
                    include=dp[sum+nums[index]][index+1];
                }
                bool exclude=dp[sum][index+1];
                dp[sum][index] = include || exclude;
            }
        }
        return dp[0][0];
    }
    bool usingSpaceOptimisation(vector<int>&nums,int target){
       // vector<vector<int>>dp(target+1,vector<int>(nums.size()+2,0));
        vector<int>prev(target+1,0);
        vector<int>curr(target+1,0);
        curr[target]=1;
        prev[target]=1;
        for(int index=nums.size()-1;index >=0;index--){
            for(int sum=target-1;sum>=0;sum--){
                bool include=0;
                if(sum + nums[index] <= target){
                    include=prev[sum+nums[index]];
                }
                bool exclude=prev[sum];
                curr[sum] = include || exclude;
            }
            prev=curr;
        }
        return curr[0];
    }

    bool canPartition(vector<int>& nums) {
        int tempSum=0;
        for(int i:nums){
            tempSum+=i;
        }
        if(tempSum & 1)return false;
        int target=tempSum/2;
        vector<vector<int>>dp(target+1,vector<int>(nums.size()+1,-1));
        return usingSpaceOptimisation(nums,target);  
    }
};
