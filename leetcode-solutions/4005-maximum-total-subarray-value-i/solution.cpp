class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        int n = nums.size();
        int s= nums[0];
        int e = nums[n-1];
        ans  = 1ll*(e-s)*k;
        return ans;
    }
};
