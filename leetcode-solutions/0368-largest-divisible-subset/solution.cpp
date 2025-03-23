class Solution {
public:
    int usingRec(vector<int>& nums,int index,int prev,vector<vector<int>>&dp){
        if(index >= nums.size()) return 0;
        int include = 0;
        if(prev == -1 || nums[index] % nums[prev] == 0) {
            include = 1 + usingRec(nums, index+1, index, dp);
        }
        int exclude = 0 + usingRec(nums,index+1,prev,dp);
        return max(include,exclude);
    }
    vector<int> usingOtherMethod(vector<int>& nums){
        vector<int>dp(nums.size()+1,1);
        int maxi=1;
        vector<int>hash(nums.size()+1,0);
        int lastIndex = 0;
        for(int index=0;index<nums.size();index++){
            hash[index] = index;
            for(int prev=0;prev < index ;prev++){
                if(nums[index] % nums[prev] == 0 && dp[index] < dp[prev]+1){
                    dp[index]=dp[prev] + 1;
                    hash[index] = prev;
                }
            }
            if(dp[index] > maxi){
                maxi=dp[index];
                lastIndex = index;
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastIndex]);
        while( hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return usingOtherMethod(nums);
    }
};
