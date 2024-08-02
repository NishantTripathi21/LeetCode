class Solution {
public:
    int findDuplicate_helper(vector<int>&nums){
        //method2 - negative markig method
        //think of element as index and mark every index negative
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i]);
            if(nums[index]<0){
                ans=index;
            }
            
            nums[index]*=-1;
            
        }
        return ans;
    }
    int findDuplicate(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        // int ans=0;
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1]){
        //         ans= nums[i];
        //     }
        // }
        return findDuplicate_helper(nums);
        
    }
};
