class Solution {
public:
    void usingRec(vector<int>& nums,vector<vector<int>>&ans,vector<int>temp,int index){
        if(index >= nums.size()){
            ans.push_back(temp);
            return;
        }
        //exclude
        usingRec(nums,ans,temp,index+1);
        //include
        temp.push_back(nums[index]);
        usingRec(nums,ans,temp,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        usingRec(nums,ans,temp,0);
        return ans;
    }
};
