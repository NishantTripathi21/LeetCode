class Solution {
public:
    void combination_helper(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&nums,int index){
        if(index >= candidates.size())return;
        if(target==0){
            ans.push_back(nums);
            return;
        }
        if(target<0) return;
        //here we used loop becuse only include nd exclude pattern will not work
        //exclude
        combination_helper(candidates,target,ans,nums,index+1);
        //include
        nums.push_back(candidates[index]);
        combination_helper(candidates,target - candidates[index],ans,nums,index);
        //bcktrack
        nums.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>nums;
        combination_helper(candidates,target,ans,nums,0);
        return ans;
        
    }
};
