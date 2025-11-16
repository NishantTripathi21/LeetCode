class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int n = nums.size();
        sum += nums[n-1] + nums[n-2];
        sum -= nums[0];
        return sum;
    }
};
