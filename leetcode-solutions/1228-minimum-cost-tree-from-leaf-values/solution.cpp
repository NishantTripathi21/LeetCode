class Solution {
public:
    int usingRecursion(vector<int>& arr, map<pair<int,int>,int>&maxi, int start, int end){
        //base 
        if(start>=end)return 0;
        int ans=INT_MAX;
        for(int i=start; i<end; i++){
            //i for partitioning
            ans=min(ans,maxi[{start,i}] * maxi[{i+1,end}] + usingRecursion(arr,maxi,start,i) + usingRecursion(arr,maxi,i+1,end) );
        }
        return ans;
    }
    int usingMemoisation(vector<int>& arr, map<pair<int,int>,int>&maxi, int start, int end,vector<vector<int>>&dp){
        //base 
        if(start>=end)return 0;
        if(dp[start][end] != -1)return dp[start][end];
        int ans=INT_MAX;
        for(int i=start; i<end; i++){
            //i for partitioning
            ans=min(ans,maxi[{start,i}] * maxi[{i+1,end}] + usingMemoisation(arr,maxi,start,i,dp) + usingMemoisation(arr,maxi,i+1,end,dp) );
        }
        dp[start][end]=ans;
        return ans;
    }
    int usingTabulation(vector<int>& arr,map<pair<int,int>,int>maxi){
        vector<vector<int>>dp(arr.size()+2,vector<int>(arr.size()+2,0));
        for(int start=arr.size()-1;start>=0;start--){
            for(int end=start+1;end<arr.size();end++){
                int ans=INT_MAX;
                for(int i=start; i<end; i++){
                    ans=min(ans,maxi[{start,i}] * maxi[{i+1,end}] + dp[start][i] + dp[i+1][end] );
                }
                dp[start][end]=ans;
            }
        }
        return dp[0][arr.size()-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;
        for(int i=0; i< arr.size(); i++){
            maxi[{i,i}]=arr[i];
            for(int j=i+1;j< arr.size() ; j++){
                maxi[{i,j}]=max(maxi[{i,j-1}],arr[j]);
            }
        }
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+2,-1));
        return usingTabulation(arr,maxi);
    }
};
