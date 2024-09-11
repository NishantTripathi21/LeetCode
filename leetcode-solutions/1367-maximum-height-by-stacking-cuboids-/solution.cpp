class Solution {
public:
    bool check(vector<int>&curr,vector<int>&prev){
        if(curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2]){
            return true;
        }
        return false;
    }
    int usingTabulation(vector<vector<int>>& nums){
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+2 , 0));
        for(int row=nums.size()-1;row>=0;row--){
            for(int col=row-1;col>=-1;col--){
                //here we have used previous index as coloumn which we passed before curr index in recusrion
                 int include=0;
                if(col==-1 || check(nums[row],nums[col])){
                    //index shifting of col-row+1;
                    //add height ,not one
                    include=nums[row][2] + dp[row+1][row+1];
                }
                int exclude=0  + dp[row+1][col+1];
                int ans=max(exclude,include);
                dp[row][col+1]=ans;
                }
        }
        return dp[0][0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid:cuboids){
            sort(cuboid.begin(),cuboid.end());
        }
        sort(cuboids.begin(),cuboids.end());
        return usingTabulation(cuboids);
    }
};
