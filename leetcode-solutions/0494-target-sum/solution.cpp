class Solution {
public:
    int usingRec(vector<int>& nums,int index,int target,int currentSum){
        // Base case
        if (index == nums.size()) {
            return (currentSum == target) ? 1 : 0;
        }
        int add = usingRec(nums, index + 1, target, currentSum + nums[index]);
        int subtract = usingRec(nums, index + 1, target, currentSum - nums[index]);

        // Return total number of ways from both options
        return add + subtract; 
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return usingRec(nums,0,target,0);
    }
};
