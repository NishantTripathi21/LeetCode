class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int st = 0;
        int ed = nums.size();
        long long sum = 0;
        while(st < ed) {
            ed=  ed-2;
            st++;
            sum += nums[ed];
        }
        return sum;
    }
};
