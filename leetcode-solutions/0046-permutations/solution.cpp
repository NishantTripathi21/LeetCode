class Solution {
public:
    void permutation(vector<int>& nums, vector<vector<int>>&ans,int index){
        //base case
        if(index>=nums.size()){
            //store ans 
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            permutation(nums,ans,index+1);
            //backtracking
            swap(nums[index],nums[i]);
        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permutation(nums,ans,0);
        return ans;
        
    }
};
