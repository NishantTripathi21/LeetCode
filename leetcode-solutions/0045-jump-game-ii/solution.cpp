class Solution {
public:
    int usingRec(vector<int>&nums,int index,vector<int>&dp){
        if( index >= nums.size() -1)return 0;
        if( nums[index] == 0)return INT_MAX;
        if(dp[index] != -1)return dp[index];
        int mini=INT_MAX;
        for( int i = index+1 ; i<= min(index + nums[index], (int)nums.size() -1 ) ;i++){
            int recAns= usingRec( nums, i,dp);
            if( recAns != INT_MAX){
                mini = min( mini ,recAns + 1);
            }
        }
        //cout<<" index: "<< index <<" mini: "<< mini<<" ";
        cout<<endl;
        return dp[index]= mini;

    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+2,-1);
        return usingRec(nums,0,dp) ;
    }
};
