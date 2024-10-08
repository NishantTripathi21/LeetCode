class Solution {
public:
    //maintain a count array to store in frequency of LIS
    int numberOf_LIS(vector<int>& nums){
        vector<int>dp(nums.size(),1);
        vector<int>count(nums.size(),1);
        int maxi=1;
        for(int index=0;index<nums.size();index++){
            for(int prev=0; prev<index; prev++){
                if(nums[index] > nums[prev] && dp[index] < dp[prev] +1){
                    dp[index]=1+ dp[prev];
                    count[index]=count[prev];
                }
                //if number of subsequence already exist, add to count
                else if(nums[index] > nums[prev] && dp[index] == dp[prev] +1){
                    count[index]=count[prev]+count[index];
                }
            }
            maxi=max(maxi,dp[index]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==maxi){
                ans=ans+count[i];
            }
        }
        return ans;
    }
    int findNumberOfLIS(vector<int>& nums) {
        return numberOf_LIS(nums);
    }
};
