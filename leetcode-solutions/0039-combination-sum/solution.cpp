class Solution {
public:
    void combination_helper(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&nums,int index){
        if(target==0){
            ans.push_back(nums);
            return;
        }
        if(target<0) return;
        for(int i=index ; i<candidates.size();i++){
            nums.push_back(candidates[i]);
            combination_helper(candidates,target-candidates[i],ans,nums,i);
            //backtracking
            nums.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>nums;
        combination_helper(candidates,target,ans,nums,0);
        return ans;
        
    }
};
