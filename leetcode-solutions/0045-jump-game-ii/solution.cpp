class Solution {
public:
    int usingRec(vector<int>&nums,int index,vector<int>&dp){
        if(index == nums.size()-1){
            return 0;
        }
        if(dp[index] != -1)return dp[index];
        int upto=nums[index];
        int jump=INT_MAX;
        //=min((int)nums.size()-1-index,upto) becuase many times we were traversing over out of bound array condition
        for(int i=1;i<=min((int)nums.size()-1-index,upto);i++){
            int temp=usingRec(nums,i+index,dp);
            if(temp!=INT_MAX){
                jump=min(jump,temp+1);
            }
        }
        return dp[index]=jump;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+2,-1);
        return usingRec(nums,0,dp);
    }
};
