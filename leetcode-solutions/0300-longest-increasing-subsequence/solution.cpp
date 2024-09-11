class Solution {
public:
    int usingRecursion(vector<int>& nums,int prev,int curr){
        if(curr >= nums.size())return 0;
        //shifting of index of previous because previous has been initialised with -1
        int include=0;
        if(prev==-1 || nums[curr] > nums[prev]){
            include=1+ usingRecursion(nums,curr,curr+1);
        }
        int exclude=0  + usingRecursion(nums,prev,curr+1);
        int ans=max(exclude,include);
        return ans;
    }

    int usingMemoisation(vector<int>& nums,int prev,int curr,vector<vector<int>>&dp){
        if(curr >= nums.size())return 0;
        //shifting of index of previous because previous has been initialised with -1
        if(dp[curr][prev+1] != -1)return dp[curr][prev+1];
        int include=0;
        if(prev==-1 || nums[curr] > nums[prev]){
            include=1+ usingMemoisation(nums,curr,curr+1,dp);
        }
        int exclude=0  + usingMemoisation(nums,prev,curr+1,dp);
        int ans=max(exclude,include);
        dp[curr][prev+1]=ans;
        return ans;
    }
    int usingTabulation(vector<int>& nums){
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+2 , 0));
        for(int row=nums.size()-1;row>=0;row--){
            for(int col=row-1;col>=-1;col--){
                //here we have used previous index as coloumn which we passed before curr index in recusrion
                 int include=0;
                if(col==-1 || nums[row] > nums[col]){
                    //index shifting of col-row+1;
                    include=1+ dp[row+1][row+1];
                }
                int exclude=0  + dp[row+1][col+1];
                int ans=max(exclude,include);
                dp[row][col+1]=ans;
                }
        }
        return dp[0][0];
    }
    int usingSpaceOptimisation(vector<int>&nums){
        vector<int>prev(nums.size()+1,0);
        vector<int>curr(nums.size()+1,0);
        for(int row=nums.size()-1;row>=0;row--){
            for(int col=row-1;col>=-1;col--){
                 int include=0;
                if(col==-1 || nums[row] > nums[col]){
                    //index shifting of col-row+1;
                    include=1+ prev[row+1];
                }
                int exclude=0  + prev[col+1];
                int ans=max(exclude,include);
                curr[col+1]=ans;
                }
            prev=curr;    

        }
        return curr[0];

    }

    //using binary search's lowerbound concept. dry run this to understand 
    int usingBS(vector<int>&nums){
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                //search for next just greater element
                int index= lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                //replace that element
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr=0;
        int prev=-1;
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+2 , -1));
        int ans=usingBS(nums);
        return ans;
    }
};
