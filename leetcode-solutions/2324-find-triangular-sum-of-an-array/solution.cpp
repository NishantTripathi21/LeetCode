class Solution {
public:
    int ans= 0;
    int solve(vector<int>& nums, int n) {
        if(n == 1){
            ans= nums[0];
            return 0;
        }

        for(int i= 0; i< n-1; i++) {
            nums[i] = (nums[i]+nums[i+1])%10;
        }
        solve(nums,n-1);
        return 0;
    }
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        solve(nums,n);
        return ans;
    }
};
