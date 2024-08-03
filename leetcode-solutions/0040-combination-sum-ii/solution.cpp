class Solution {
public:
    void combination_helper(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&nums,int index){
        if(target==0){
            ans.push_back(nums);
            return;
        }
        if(target<0) return;
        for(int i=index ; i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            nums.push_back(candidates[i]);
            combination_helper(candidates,target-candidates[i],ans,nums,i+1);
            //backtracking
            nums.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>nums;
        set<vector<int>>ansr;
        combination_helper(candidates,target,ans,nums,0);
        for(auto e:ans){
            ansr.insert(e);
        }
        ans.clear();
        for(auto i: ansr){
            ans.push_back(i);
        }
        return ans;

        
    }
};
