class Solution {
public: 
    int method( int target, vector<int>& nums){
        int minSize = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;
        while( right < nums.size()){
            sum += nums[right];
            while( sum >= target){
                minSize = min( minSize,right-left+1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return minSize==INT_MAX? 0: minSize;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        return method(target,nums);
    }
};
