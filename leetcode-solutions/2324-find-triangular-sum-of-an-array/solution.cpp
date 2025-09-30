class Solution {
public:
    void solve(vector<int>& nums, int n) {
        if(n == 1)return;
        for(int i= 0; i< n-1; i++) {
            nums[i]= (nums[i] + nums[i+1])%10;
        }
        solve(nums,n-1);
    }
    int triangularSum(vector<int>& nums) {
        solve(nums,nums.size());
        return nums[0]%10;
    }
}; 
